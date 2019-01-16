//Commented by Shravan////////////////////////////////////////

//ESP8266 core library

#include<ESP8266WiFi.h>

//pin used for o/p on NodeMCU
#define LED D2 


//WiFi credentials
//Recomended configuration:
//Create your Hotspot and give your uid and pwd below 
// to connect NodeMCU to your WiFi
const char* ssid = "########";
const char* pwd = "#########";


//flag for led toggling
unsigned char status_led = 0;

//Creation of server object
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(LED,OUTPUT);

Serial.println();
Serial.println();
Serial.print("Connecting to...");
Serial.println(ssid);

WiFi.begin(ssid,pwd);

//wait till WiFi is connected to router/internet
while(WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected to your local network!!!");

  server.begin();
  Serial.println("Server successfully started!");
  Serial.println("Your Node McU was alloted a IP address by your Local Router!!!");
  Serial.println("Node McU IP address: ");
  Serial.print(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

  //creation of client object and check for server availability
  WiFiClient client = server.available();

  //if no client, return to wait state
  if(!client){
    return; }

    Serial.println("new client detected..");

    //Wait for client identification
    while(!client.available()){
      delay(1);
      }

      //prepare client request
      String req = client.readStringUntil('\r');
      Serial.println(req);
      
      //flushing the client tunnel for upcoming clinet req
      client.flush();

      //verify the type of req
      if(req.indexOf("/ledoff") != -1)
      {
        status_led = 0;
        digitalWrite(LED,LOW);
        Serial.println("LED OFF");
        
        }

        //verify the type of req
        else if(req.indexOf("/ledon") != -1)
        {
          status_led = 1;
          digitalWrite(LED,HIGH);
          Serial.println("LED ON");
          }

          //Create embedded HTML for web page creation
             client.println("HTTP/1.1 200 OK");
             client.println("Content-Type:text/html");
             client.println("Connection:close");
             client.println("");

             client.println("<!DOCTYPE HTML>");
             client.println("<HTML>");
            
             client.println("<H1>WELCOME TO INSOFE NODE McU SERVER APPLICATION</H1>");
             client.println("<br/>");
             client.println("<H1>CLICK THE BELOW BUTTONS TO TOGGLE LEDs</H1>");
             client.println("<br/>");
             client.println("<H1>LED CONTROL</H1>");
             client.println("<br/>");
             client.println("<a href=\"/ledon\"\"><button style=FONT-SIZE:16px;BACKGROUND-COLOR: #4CAF50;BORDER:none;COLOR:WHITE;TEXT-ALLIGN:CENTER;HEIGHT:100px;WIDTH:100px;126px;Z-INDEX:0;TOP:150px:>LED ON</button></a>");
             client.println("<a href=\"/ledoff\"\"><button style=FONT-SIZE:16px;BACKGROUND-COLOR: #4CAF50;BORDER:none;COLOR:WHITE;TEXT-ALLIGN:CENTER;HEIGHT:100px;WIDTH:100px;126px;Z-INDEX:0;TOP:150px:>LED OFF</button></a>");

             client.println("</HTML>");

             delay(1);

             //statement used for client disconnection
             Serial.println("Client disconnected");
             Serial.println("");

}
