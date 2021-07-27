int val1;
int val2;

#define ENABLE1 5
#define ENABLE2 6
#define DIRA 3
#define DIRB 4
#define DIRC 7
#define DIRD 8
#define joystick1 A0
#define joystick2 A1


void setup() {
  pinMode(joystick1, INPUT);
  pinMode(joystick2, INPUT);
  pinMode(ENABLE1,OUTPUT);
  pinMode(ENABLE2,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(DIRC,OUTPUT);
  pinMode(DIRD,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val1 = analogRead(joystick1);
  val2 = analogRead(joystick2);

  if(val1 > 600) {
    val1 = map(val1, 600, 0, 0, 255);
    digitalWrite(ENABLE1,HIGH);
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,HIGH);
  }

  else if(val1 < 400) {
    val1 = map(val1, 400, 0, 0, 255);
    digitalWrite(ENABLE1,HIGH);
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
  }

  else {
    digitalWrite(ENABLE1,LOW);
  }

  if(val2 > 600) {
    val2 = map(val2, 600, 0, 0, 255);
    digitalWrite(ENABLE2,HIGH);
    digitalWrite(DIRC,HIGH);
    digitalWrite(DIRD,LOW);
  }
  
  else if(val2 < 400) {
    val2 = map(val2, 400, 0, 0, 255);
    digitalWrite(ENABLE2,HIGH);
    digitalWrite(DIRC,LOW);
    digitalWrite(DIRD,HIGH);
  }

  else {
    digitalWrite(ENABLE2,LOW);
  }

}
