//LED example for demo

void setup() {
  // LED pin setup and type (O/P or I/P)
#define LED 2 
pinMode(LED,OUTPUT);
}

//Loop function to run the program continuosly
void loop() {
digitalWrite(LED,HIGH); // Turning ON LED
delay(1000); //1 sec delay 
digitalWrite(LED,LOW); // Turning OFF LED
delay(1000);

}
