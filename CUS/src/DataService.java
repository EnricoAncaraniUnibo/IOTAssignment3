
import io.vertx.core.AbstractVerticle;
import io.vertx.core.http.HttpServerResponse;
import io.vertx.core.json.JsonArray;
import io.vertx.core.json.JsonObject;
import io.vertx.ext.web.Router;
import io.vertx.ext.web.RoutingContext;
import io.vertx.ext.web.handler.BodyHandler;
import java.util.Date;
import java.util.LinkedList;

/*
 * Data Service as a vertx event-loop 
 */
public class DataService extends AbstractVerticle {

	private int port;
	private static final int MAX_SIZE = 10;
	private LinkedList<Double> waterLevels;
	private Controller controller;
	
	public DataService(int port, Controller controller) {
	    this.port = port;
        this.controller = controller;
        this.waterLevels = new LinkedList<>();
	}

	@Override
	public void start() {		
		Router router = Router.router(vertx);
		router.route().handler(BodyHandler.create());
		router.route("/*").handler(io.vertx.ext.web.handler.StaticHandler.create("../DBS"));
		router.get("/api/data").handler(this::handleGetData);
		router.post("/api/state").handler(this::handleChangeMode);
		router.post("/api/valve").handler(this::handleSetValve);
		vertx
			.createHttpServer()
			.requestHandler(router)
			.listen(port);

		log("Service ready on port: " + port);
	}
	
	public void addWaterLevel(double level) {
        waterLevels.addFirst(level);
        if (waterLevels.size() > MAX_SIZE) {
            waterLevels.removeLast();
        }
    }
	
	private void handleChangeMode(RoutingContext routingContext) {
		HttpServerResponse response = routingContext.response();
		JsonObject res = routingContext.getBodyAsJson();
		if (res == null) {
			sendError(400, response);
		} else {
			String state = res.getString("state");
			if (state.equals("AUTOMATIC")) {
                controller.pushAutomatic();
            } else if (state.equals("MANUAL")) {
                controller.pushManual();
            }
			response.setStatusCode(200).end();
		}
	}
	
	private void handleGetData(RoutingContext routingContext) {
		JsonObject obj = new JsonObject();
		obj.put("state", controller.state.toString());
		obj.put("valveValue", controller.valve);
		JsonArray arr = new JsonArray();
		for (Double d: waterLevels) {
			arr.add(d);
		}
		obj.put("waterLevels", arr);
		routingContext.response()
			.putHeader("content-type", "application/json")
			.end(obj.encodePrettily());
	}
	
	private void handleSetValve(RoutingContext routingContext) {
        JsonObject body = routingContext.getBodyAsJson();
        int value = body.getInteger("valve");
        
        if (controller.state == Controller.State.MANUAL) {
            controller.pushValve(value);
            routingContext.response().setStatusCode(200).end();
        } else {
            routingContext.response().setStatusCode(403).end("Not in Manual Mode");
        }
    }
	
	private void sendError(int statusCode, HttpServerResponse response) {
		response.setStatusCode(statusCode).end();
	}

	private void log(String msg) {
		System.out.println("[DATA SERVICE] "+msg);
	}

}