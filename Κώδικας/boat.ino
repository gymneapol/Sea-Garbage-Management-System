// ΟΜΑΔΑ STEAΜ ΓΥΜΝΑΣΙΟΥ ΝΕΑΠΟΛΗΣ ΛΑΣΙΘΙΟΥ
#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo;
SoftwareSerial MyBlue(10, 11); // RX | TX 

int motor1pin1 = 4;
int motor1pin2 = 5;
int speedpin=6;
char val;
long mspeed=0;


void setup() 
{
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(speedpin, OUTPUT);

  myservo.attach(3);
  Serial.begin(9600);
  MyBlue.begin(9600);
}
  

void loop() 
{
  if (MyBlue.available())
   {
    Serial.println("***");
    val = MyBlue.read(); 
    Serial.println("***");
    Serial.println(val);     
    Serial.println("***");

    
    if (val=='L')
    {
     Serial.println("left");
     myservo.write(140);      
    }
    if (val=='R')
    {
     Serial.println("right");
     myservo.write(40);
    }
    if (val=='F')
    {
     Serial.println("forward"); 
     if (mspeed <= 245)
     {
       if (mspeed<0)
      {
        mspeed=mspeed+10;
        //Controlling speed (0 = off and 255 = max speed):     
        analogWrite(speedpin, abs(mspeed)); //ENA pin  
        // put your main   code here, to run repeatedly:   
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2,HIGH);           
      }else
      {
        mspeed=mspeed+10;
        //Controlling speed (0 = off and 255 = max speed):     
        analogWrite(speedpin, abs(mspeed)); //ENA pin  
        digitalWrite(motor1pin1, HIGH);
        digitalWrite(motor1pin2, LOW);             
      }
     }
    }
    if (val=='B')
    {
     Serial.println("back");
     if (mspeed >= 10)
     {     
      mspeed=mspeed-10;
       Serial.println(mspeed);
      //Controlling speed (0 = off and 255 = max speed):     
      analogWrite(speedpin, mspeed); //ENA pin  
      // put your main   code here, to run repeatedly:   
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);                
     }else
     {
      mspeed=mspeed-10;
      Serial.println(mspeed);
      //Controlling speed (0 = off and 255 = max speed):     
      analogWrite(speedpin, abs(mspeed)); //ENA pin  
       digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2,HIGH);                      
     }
    }
    Serial.println(mspeed);
    MyBlue.write(mspeed);
    delay(1000);
  }
}
