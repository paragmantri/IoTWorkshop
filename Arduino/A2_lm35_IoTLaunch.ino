//Demo showing a Analog temperarure sensor

int val;
int temppin = 1; //Analog pin A1
#define LED 2 //defining the LED pin

void setup() {
  pinMode(LED,OUTPUT); //configure as O/P
  // Serial driver invoke
Serial.begin(9600);

}

void loop() {
  
val = analogRead(temppin); //Reading the analog sensor val and storing in val

//ADC conversion formula 

/*1024 represent 10-bit ADC
Each value is divided by 1024 to get a voltage level
The multiplying factor is 5000 when 5V is used and 3300 when 3.3 is used
*/

float mv = (val/1024.0)*5000;

float cel = mv/10;
//float faren = (cel*9)/5 + 32; //conversion from cel to farenheit

Serial.print("Temp = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);

//if temp >= 30, LED will glow else not glow
if(cel >= 30)
{digitalWrite(LED,HIGH);}
else
digitalWrite(LED,LOW);

}
