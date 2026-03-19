

import org.eclipse.paho.client.mqttv3.*;

/**
 * 
 * A simple example of Java MQTT client subscribing
 * a topic, using PAHO Eclipse library.
 * 
 * 
 */

public class SimpleSubscriber {

    Controller controller;
    public void start(Controller con) throws Exception {
        controller = con;
        String broker = "tcp://broker.mqtt-dashboard.com";
        String clientId = "assignment3-" + System.currentTimeMillis();
        String topic = "MSG";

        MqttClient client = new MqttClient(broker, clientId);

        // Callback to handle messages and connection events
        client.setCallback(new MqttCallback() {
            @Override
            public void connectionLost(Throwable cause) {
                controller.loseConnection();
            }

            @Override
            public void messageArrived(String topic, MqttMessage message) {
                controller.manageMessage(new String(message.getPayload()));
            }

            @Override
            public void deliveryComplete(IMqttDeliveryToken token) {
                // Not used for subscribers
            }
        });

        client.connect();
        if (client.isConnected()) {
            controller.onConnected();
        } else {
            System.out.println("Connessione fallita!");
            controller.loseConnection();
        }
        
        
        /*
         * Subscribing - second param is the QoS (from broker to receiver)
         * 
         * - 0: at most once (minimum)
         * - 1: at least once
         * - 2: exactly once (maximum)
         */
        client.subscribe(topic, 1);

        System.out.println("Subscribed to topic: " + topic);

        // Keep the program running to listen for messages
        Thread.sleep(60000);
        client.disconnect();
        client.close();
    }
}
