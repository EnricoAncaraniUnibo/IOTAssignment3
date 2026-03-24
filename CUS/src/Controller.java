import io.vertx.core.Vertx;

public class Controller {
    
    static final String CMD_CLOSE = "cmd:CLOSE";
    static final String CMD_OPEN    = "cmd:OPEN";
    static final String CMD_HALF    = "cmd:HALF";
    static final String ST_UNCON    = "st:UNCONNECTED";

    public enum State {
        AUTOMATIC, MANUAL, UNCONNECTED
    }
    
    State state;
    SerialCommChannel channel;
    long startTime;
    long lastMsgTime = 0;
    
    public Controller() throws Exception {
        channel = new SerialCommChannel(Config.Port,115200);   
    }
    
    public static void main(String[] args) throws Exception {
        
        Controller controller = new Controller();
        SimpleSubscriber sub = new SimpleSubscriber();
        sub.start(controller);
        new MonitoringAgent(controller.channel,controller).start();
        controller.lastMsgTime = System.currentTimeMillis();
        new Thread(() -> {
            while(true) {
                if(System.currentTimeMillis() - controller.lastMsgTime > Config.T2) {
                    if(controller.state==State.AUTOMATIC) {
                        controller.loseConnection();
                    }
                }
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }

    public void loseConnection() {
       if(state==State.AUTOMATIC) {
           state = State.UNCONNECTED;
           channel.sendMsg(ST_UNCON);
       }
    }
    
    public void manageMessage(String string) {
        if(state==State.UNCONNECTED) {
            automatic();
        }
        lastMsgTime = System.currentTimeMillis();
        if(state==State.AUTOMATIC) {
            System.out.println(string);
            float value = Float.parseFloat(string);
            if(value>Config.L2) {
                channel.sendMsg(CMD_OPEN);
            }else {
                if(value<Config.L1) {
                    startTime=0;
                    channel.sendMsg(CMD_CLOSE);
                }else {
                    if(startTime>0) {
                        if(System.currentTimeMillis() - startTime > Config.T1) {
                            channel.sendMsg(CMD_HALF);
                        }
                    }else {
                        startTime=System.currentTimeMillis();
                        channel.sendMsg(CMD_CLOSE);
                    }
                }
            } 
        }
    }

    public void automatic() {
        state = State.AUTOMATIC;
        
    }

    public void manual() {
        state = State.MANUAL;
        
    }
}