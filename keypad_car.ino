#include <SoftwareSerial.h>
int motor1Pin1 = 8;
int motor1Pin2 = 9;
int motor2Pin1 = 6;
int motor2Pin2 = 7;
int ENA=10;
int ENB=11;

SoftwareSerial BT(1,0);

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  Serial.begin(9600);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);

}
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(ENA,100);
  analogWrite(ENB,100);
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(ENA,70);
  analogWrite(ENB,70);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(ENA,70);
  analogWrite(ENB,70);
  delay(500);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(ENA,70);
  analogWrite(ENB,70);
  delay(500);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}


void loop() {
  if(BT.available()){
    char command=BT.read();
    Serial.println(command);
    switch(command) {
      case 'F': moveForward(); break;
      case 'B': moveBackward(); break;
      case 'S': stopMotors(); break;
      case 'L': turnLeft(); break;
      case 'R': turnRight(); break;
      default: stopMotors(); break;
    }
  }
}

