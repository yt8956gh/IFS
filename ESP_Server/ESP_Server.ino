#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "DHT.h"
#include "EmonLib.h" 

#define _baudrate   9600
#define _dhtpin     5
#define _dhttype    DHT22

#define Timing 1000 //The cycle of updating data to Raspberry Pi server
#define HOST    "192.168.1.254" // ThingSpeak IP Address: 184.106.153.149
#define PORT    8700
#define Rated_Voltage 110.0 

//const char *ssid = "n1an";
//const char *password = "11151997";

const char *ssid = "ISDC_AC";
const char *password = "8131081313";

float temperature, humidity;
double Irms;
String GET = "GET https://api.thingspeak.com/update?api_key=CD13ZET4SV4IZ8G5";
int times;

ESP8266WebServer server ( 80 );
DHT dht( _dhtpin, _dhttype );
EnergyMonitor emon1;

const int led = 13;
int height[40];

void handleRoot() {

	digitalWrite ( led, 1 );
	char temp[500];
	int sec = millis() / 1000;
	int min = sec / 60;
	int hr = min / 60;

	snprintf ( temp, 500,

"<html>\
  <head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>ESP8266 Demo</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>\tIFS Server</h1>\
    <h5>\tIntelligent Factory System Server</h5>\
    <p>\tUptime: %02d:%02d:%02d</p>\
    <p>\tTemperature: %.2f C</p>\
    <p>\tHumidity: %.2f %%</p>\
    <p>\tApparent power: %.2f W</p>\
    <p>\tIrms: %.2f A</p>\
  </body>\
</html>",

		hr, min % 60, sec % 60, temperature, humidity, Irms*Rated_Voltage, Irms
	);
	server.send ( 200, "text/html", temp );
	digitalWrite ( led, 0 );
}

void handleNotFound() {
	digitalWrite ( led, 1 );
	String message = "File Not Found\n\n";
	message += "URI: ";
	message += server.uri();
	message += "\nMethod: ";
	message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
	message += "\nArguments: ";
	message += server.args();
	message += "\n";

	for ( uint8_t i = 0; i < server.args(); i++ ) {
		message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
	}

	server.send ( 404, "text/plain", message );
	digitalWrite ( led, 0 );
}

void setup ( void ) {

  Serial.begin( _baudrate );
  //Serial.begin ( 115200 );//original
	pinMode ( led, OUTPUT );
	digitalWrite ( led, 0 );


  dht.begin();
  Serial.println( "dht Ready!" );

  emon1.current(0, 65);
  Serial.println( "CT Ready!" );
  
	WiFi.mode ( WIFI_STA );
	WiFi.begin ( ssid, password );
	Serial.println ( "" );


  for(int i=0;i<40;i++) height[i]=0;

	// Wait for connection
	while ( WiFi.status() != WL_CONNECTED ) {
		delay ( 500 );
		Serial.print ( "." );
	}

	Serial.println ( "" );
	Serial.print ( "Connected to " );
	Serial.println ( ssid );
	Serial.print ( "IP address: " );
	Serial.println ( WiFi.localIP() );

	if ( MDNS.begin ( "esp8266" ) ) {
		Serial.println ( "MDNS responder started" );
	}

	server.on ( "/", handleRoot );
	server.on ( "/inline", []() {
		server.send ( 200, "text/plain", "this works as well" );
	} );
	server.onNotFound ( handleNotFound );
	server.begin();
  delay(2000);
	Serial.println ( "HTTP server started" );
}


void getSensorData()
{
  Irms = emon1.calcIrms(1480); 
  Serial.print("Apparent power: ");
  Serial.print(Irms*Rated_Voltage);         // Apparent power
  Serial.print(", Irms: ");
  Serial.println(Irms);          // Irms
    
  humidity    = dht.readHumidity();
  temperature = dht.readTemperature();

  Serial.print( "Humidity: " );
  Serial.print( humidity );
  Serial.print( ", Temperature: " );
  Serial.println( temperature );
  Serial.println("");
}

void loop ( void ) {
  times++;
  
  getSensorData();
	server.handleClient();
  
  if( isnan( humidity ) || isnan( temperature ) )
  {
      Serial.println( "Failed to read form dht" );
      return;
  }
  else
  {  
      updatedht();// upload data to ThingSpeak
  }

  delay(Timing);
  
}


void updatedht()
{
    // 設定 ESP8266 作為 Client 端
    WiFiClient client;
    if( !client.connect( HOST, PORT ) )
    {
        Serial.println( "Connection Failed" );
        return;
    }
    else
    {
      
        char sendStr[100]={};
        //sprintf(sendStr,"{\"C\": %d,\"RH\": %d,\"W\":%.2f}",(int)temperature,(int)humidity,(float)Irms*Rated_Voltage);
        sprintf(sendStr,"%d,%d,%.2f",(int)temperature,(int)humidity,(float)Irms*Rated_Voltage); //目前用CSV格式，日後預計使用json
        
        client.print( sendStr );
        
        delay(10);

        client.stop();
    }
}
