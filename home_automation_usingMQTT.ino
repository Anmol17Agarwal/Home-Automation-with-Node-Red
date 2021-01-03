#include <ESP8266WiFi.h>
#include <PubSubClient.h>  //callback    //reconnect 

// Update these with values suitable for your network.

const char* ssid = "AndriodAP_7807";          // SSID for your wifi Router
const char* passkey = "123456789";  //Password for wifi Router

const char* mqtt_server = "mqtt.fluux.io:1883";  //mqtt server domain or IP
const char* topic = "testing01";    // topic for mqtt

const char* username = "";   //username for mqtt broker
const char* password = "";  // password for mqtt broker



WiFiClient espClient;
PubSubClient client(espClient);


void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, passkey);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String topicstr = topic;
   char sub[1000];
   int c =0;
  Serial.print("Message arrived [");        // Message Arrived [test] a
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();


  if ((char)payload[0] == 'a') {
    digitalWrite(D4, LOW); 
    //client.publish("testing/publish","a",false);
   // Serial.println("D4 is OFF");  
  }if ((char)payload[0] == 'b'){
    digitalWrite(D4, HIGH); 
    //Serial.println("D4 is ON");
    //client.publish("testing/publish","b",false);
  }if ((char)payload[0] == 'c') {
    digitalWrite(D6, LOW); 
   // client.publish("testingpub","c",false);  
  }if ((char)payload[0] == 'd'){
    digitalWrite(D6, HIGH);  
    //client.publish("testingpub","d",false);
  }if ((char)payload[0] == 'e') {
    digitalWrite(D7, LOW);  
    client.publish("testingpub","e",false);
  }if ((char)payload[0] == 'f'){
    digitalWrite(D7, HIGH); 
    client.publish("testingpub","f",false); 
  }if ((char)payload[0] == 'g') {
    digitalWrite(D3, LOW);  
    client.publish("testingpub","g",true);
  }if ((char)payload[0] == 'h'){
    digitalWrite(D3, HIGH); 
    client.publish("testingpub","h",false);
  }




}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
      String clientId = "Nodemcu";
    // Attempt to connect
    if (client.connect(clientId.c_str(),username,password, "test", 0,0,"Mqtt disconnected") ) { // will message 
       Serial.println("connected");
       client.publish("test","MQTT SUCCESSFULLY CONNECTED",true);
       client.subscribe(topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(D4, OUTPUT); 
  pinMode(D6, OUTPUT); 
  pinMode(D7, OUTPUT); 
  pinMode(D3, OUTPUT);
  //pinMode(D0, INPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server,1884);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
