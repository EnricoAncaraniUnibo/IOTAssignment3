public class Controller {

    public enum State {
        AUTOMATIC, MANUAL, UNCONNECTED
    }
    
    State state;
    
    public static void main(String[] args) throws Exception {
        Controller controller = new Controller();
        SimpleSubscriber sub = new SimpleSubscriber();
        sub.start(controller);
    }

    public void loseConnection() {
       state = State.UNCONNECTED;
        
    }

    public void manageMessage(String string) {
        // TODO Auto-generated method stub
        
    }

    public void onConnected() {
       state = State.AUTOMATIC;
        
    }
}