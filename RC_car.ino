#define EN1 5
#define EN2 6
#define IN1 8
#define IN2 9
#define IN3 11
#define IN4 10
#define MAX_SPEED 255

int x = 0;
int speedVal = 0;
int motorTurnSpeed = 75;


void setup() {
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

// function to control the speed of the 2 DC motors
// the direction is given by the 2 input pins, while
// the speed is given through the enable pin

void motorSpeed(int a, int b) {
  if (a >= 0) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, a);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(EN1, -a);
  }
  
  if (b >= 0) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN2, b);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN2, -b);
  }
}


void loop() {
   // read the signal coming from the application
    if (Serial.available() >= 1) {
    x = Serial.read();
    speedVal = Serial.read();
    Serial.println(x);
  }
  if(x == '1') motorSpeed(MAX_SPEED,MAX_SPEED);
  if(x == '2') motorSpeed(-motorTurnSpeed,motorTurnSpeed);
  if(x == '3') motorSpeed(-MAX_SPEED,-MAX_SPEED);
  if(x == '4') motorSpeed(motorTurnSpeed,-motorTurnSpeed);
  if(x == '0') motorSpeed(0,0);
  
}
