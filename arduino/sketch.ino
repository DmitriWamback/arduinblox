#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// (uses the ESP8266 WiFi module)

const char* ssid = "ssid";
const char* pass = "pass";

const int led = 0; // D3 pin

void setup() {
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    
    Serial.begin(9600);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
    }
}

String ipaddr = "ip";
String port = "8080";
String geturl = "/dat";

void loop() {
    HTTPClient w_client;
    w_client.begin("http://"+ipaddr+":"+port+""+geturl);

    int http = w_client.GET();
    
    if (http > 0) {
        String payLoad = w_client.getString();
        Serial.println(payLoad);
        if (payLoad == "{ \"isOn\": true }") digitalWrite(led, HIGH);
        else digitalWrite(led, LOW);
    }
    Serial.flush();
    delay(10);
}
