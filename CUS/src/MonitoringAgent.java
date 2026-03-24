
public class MonitoringAgent extends Thread {

	SerialCommChannel channel;
	Controller con;
	
	public MonitoringAgent(SerialCommChannel channel, Controller con) throws Exception {
		this.channel = channel;
		this.con = con;
	}
	
	public void run(){
		while (true){
			String msg;
            try {
                msg = channel.receiveMsg();
                System.out.println("Received from serial: " + msg);
                if (msg.equals("AUTOMATIC")){
                    con.automatic();
                }else if(msg.equals("MANUAL")) {
                    con.manual();
                }else {
                    try {
                        int value = Integer.parseInt(msg);
                        con.setValve(value);
                    }catch(Exception ex) {
                        ex.printStackTrace();
                    }
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }	
			
		}
	}

}
