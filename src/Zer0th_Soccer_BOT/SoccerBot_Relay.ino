// Bluetooth RC Robot
// Programmed By NSU_Zer0th

#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2);

const int rightMotForward = 12;
const int rightMotBackward = 11;
const int leftMotForward = 9;
const int leftMotBackward = 10;

byte serialA;

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(rightMotForward, OUTPUT);
  pinMode(rightMotBackward, OUTPUT);
  pinMode(leftMotForward, OUTPUT);
  pinMode(leftMotBackward, OUTPUT);
}

void loop() {

  if (mySerial.available() > 0) {
    serialA = mySerial.read();
    Serial.println(serialA);
  }
  switch (serialA) {
    // forward
    case 'F':
      Serial.println("F");
      digitalWrite(rightMotForward, HIGH);
      digitalWrite(rightMotBackward, LOW);
      digitalWrite(leftMotForward, HIGH);
      digitalWrite(leftMotBackward, LOW);
      break;

    // left
    case 'L':
      Serial.println("L");
      digitalWrite(rightMotForward, HIGH);
      digitalWrite(rightMotBackward, LOW);
      digitalWrite(leftMotForward, LOW);
      digitalWrite(leftMotBackward, HIGH);
      break;

    // right
    case 'R':
      Serial.println("R");
      digitalWrite(rightMotForward, LOW);
      digitalWrite(rightMotBackward, HIGH);
      digitalWrite(leftMotForward, HIGH);
      digitalWrite(leftMotBackward, LOW);
      break;

    // backward
    case 'B':
      Serial.println("B");
      digitalWrite(rightMotForward, LOW);
      digitalWrite(rightMotBackward, HIGH);
      digitalWrite(leftMotForward, LOW);
      digitalWrite(leftMotBackward, HIGH);
      break;

    // Stop
    case 'S':
      digitalWrite(rightMotForward, LOW);
      digitalWrite(rightMotBackward, LOW);
      digitalWrite(leftMotForward, LOW);
      digitalWrite(leftMotBackward, LOW);
  }
}
