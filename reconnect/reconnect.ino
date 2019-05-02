#include <ESP8266WiFi.h>

/*****************************************************************
/* Configuration part start                                      *
/*****************************************************************/
const char* ssid = "foo";
const char* password = "foo";
const char* host = "192.168.10.1";
int port = 80;
/*****************************************************************
/* Configuration part end                                        *
/*****************************************************************/

void sendData(){
	WiFiClient client;
	
	Serial.printf("\n[Connecting to %s ... ", host);
	if (client.connect(host, port)){
		Serial.println("connected]");
		
		Serial.println("[Sending a request]");
		
		client.print(String("GET /") + " HTTP/1.1\r\n" +
                 "Host: " + host + ":" + port + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );
				
		Serial.println("[Response:]");
		while (client.connected() || client.available()){
			if (client.available()){
				String line = client.readStringUntil('\n');
				Serial.println(line);
			}
		}
		client.stop();
		Serial.println("\n[Disconnected]");
	}
	else{
		Serial.println("connection failed!]");
		client.stop();
	}
}

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);

  // Wait for serial to initialize.
  while(!Serial) { }
  
  Serial.println("I'm awake.");
  
  Serial.printf("Connecting to %s ", ssid);
  int retry_count = 0;
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED && retry_count < 20)
  {
	  delay(500);
	  Serial.print(".");
	  retry_count++;
  }
  
  Serial.println(" connected");
  
  if (WiFi.status() == WL_CONNECTED){
	  sendData();
  }

  Serial.println("Going into deep sleep for 20 seconds");
  ESP.deepSleep(20e6);
}

void loop() {
}