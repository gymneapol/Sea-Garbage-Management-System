// ΟΜΑΔΑ STEAΜ ΓΥΜΝΑΣΙΟΥ ΝΕΑΠΟΛΗΣ ΛΑΣΙΘΙΟΥ
#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
SoftwareSerial MyBlue(10, 11); // RX | TX 

char val;


void setup() {
  Serial.begin(9600);
  MyBlue.begin(9600);
 }

void loop() {
 
   if (MyBlue.available())
   {
    val = MyBlue.read(); // read bluetooth values
    delay(150);
    if (val=='B')
    {
     Serial.println("Backwards");
     myservo.attach(3);
     myservo.write(110);  // turn servo clockwise value > 90
     delay(220);
     myservo.detach(); // stop servo

    }
    if (val=='F')
    {
     Serial.println("Forward");
     myservo.attach(3);     
     myservo.write(80); // turn servo counterclockwise value < 90
     delay(180);
     myservo.detach();
    }
   if (val=='R')
    {
     Serial.println("Right");      
     myservo2.attach(5);
     myservo2.write(80);
     delay(150);
     myservo2.detach();
    }
    if (val=='L')
    {
     Serial.println("Left");
     myservo2.attach(5);     
     myservo2.write(110);
     delay(150);
     myservo2.detach();
    }    
     Serial.println("***");
     Serial.println(val);     
     Serial.println("***");     
     val = MyBlue.read(); 
   }
   delay(100);
}
