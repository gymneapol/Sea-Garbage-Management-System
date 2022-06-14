// ΟΜΑΔΑ STEAΜ ΓΥΜΝΑΣΙΟΥ ΝΕΑΠΟΛΗΣ ΛΑΣΙΘΙΟΥ

#define A 8
#define B 9
#define C 10
#define D 11
#define NUMBER_OF_STEPS_PER_REV 512

const int BUTTON1 = 6;
const int BUTTON2 = 5;
const int trigPin = 2; // το pin 11 στέλνει τα υπερηχητικά σήματα (triger)
const int echoPin = 3;

long duration; // μεταβλητή που μετράμε το χρόνο που κάνει το σήμα να πάει και να επσιτρέψει
int distance;

int currentState1=99;
int currentState2=99;
void write(int a,int b,int c,int d){
  digitalWrite(A,a);
  digitalWrite(B,b);
  digitalWrite(C,c);
  digitalWrite(D,d);
}

//ένα βήμα μπροστά στον stepper motor
void onestepforward(){
  write(1,0,0,0);
  delay(2);
  write(1,1,0,0);
  delay(2);
  write(0,1,0,0);
  delay(2);
  write(0,1,1,0);
  delay(2);
  write(0,0,1,0);
  delay(2);
  write(0,0,1,1);
  delay(2);
  write(0,0,0,1);
  delay(2);
  write(1,0,0,1);
  delay(2);
}

//ένα βήμα πίσω στον stepper motor
void onestepbackward(){
  write(1,0,0,1);
  delay(2);
  write(0,0,0,1);
  delay(2);
  write(0,0,1,1);
  delay(2);
  write(0,0,1,0);
  delay(2);
  write(0,0,1,0);
  delay(2);
  write(0,1,1,0);
  delay(2);
  write(0,1,0,0);
  delay(2);
  write(1,1,0,0);
  delay(2);
  write(1,0,0,0);
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);

pinMode(trigPin, OUTPUT); // το triger pin είναι OUTPUT αφού στέλνει σήμα
pinMode(echoPin, INPUT); // το echo pin είναι INPUT αφού λαμβάνει σήμα
}

void loop() {
  currentState1 = digitalRead(BUTTON1);
  if (currentState1==LOW)
  {
    onestepforward();
  }
  currentState2 = digitalRead(BUTTON2);
  if (currentState2==LOW)
  {
    onestepbackward();
  }


  // Clears the trigPin
digitalWrite(trigPin, LOW); // σιγουρευόμαστε ότι το trigger δεν στέλνει τίποτα
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH); // στέλνουμε υπερηχητικό σήμα
delayMicroseconds(10); //για 10 μικορδευτερόλεπα
digitalWrite(trigPin, LOW); // σταματάμε να στέλνουμε υπερηχητικό σήμα
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH); //διαβάζουμε το σήμα που έχει επιστρέψει
distance= duration*0.034/2; //υπολογίζουμε την απόσταση σύμφωνα με την θεωρία που είδαμε
// στην προηγούμενη διαφάνεια
Serial.print("Distance: "); //Εκτυπώνουμε στο serial monitor την λέξη distance
Serial.println(distance); //εκτυπώνουμε στο serial monitor την απόσταση που υπολογίσαμε
}
