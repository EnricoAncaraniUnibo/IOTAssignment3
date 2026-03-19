public class Controller {
    
    static final String CMD_CLOSE = "cmd:CLOSE";
    static final String CMD_OPEN    = "cmd:OPEN";
    static final String CMD_HALF    = "cmd:HALF";

    public enum State {
        AUTOMATIC, MANUAL, UNCONNECTED
    }
    
    State state;
    SerialCommChannel channel;
    long startTime;
    
    public Controller() throws Exception {
        channel = new SerialCommChannel(Config.Port,115200);   
    }
    
    public static void main(String[] args) throws Exception {
        
        Controller controller = new Controller();
        SimpleSubscriber sub = new SimpleSubscriber();
        sub.start(controller);
    }

    public void loseConnection() {
       state = State.UNCONNECTED;
        
    }

    public void manageMessage(String string) {
        if(state==State.AUTOMATIC) {
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

    public void onConnected() {
       state = State.AUTOMATIC;
        
    }
}