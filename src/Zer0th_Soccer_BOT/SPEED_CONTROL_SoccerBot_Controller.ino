// Bluetooth RC Robot
// Programmed By NSU_Zer0th

//MOTOR1
const int motor1Pin1 = 13;
const int motor1Pin2 = 12;
const int enablem1Pin3 = 10;

//MOTOR2
const int motor2Pin1 = 8;
const int motor2Pin2 = 9;
const int enablem2Pin3 = 11;

//MOTOR3
const int motor3Pin1 = 2;
const int motor3Pin2 = 4;
const int enablem3Pin3 = 3;

//MOTOR4
const int motor4Pin1 = 6;
const int motor4Pin2 = 7;
const int enablem4Pin3 = 5;

byte serialA;
int state;
int defaultSpeed = 220;

void setup() {

  Serial.begin(9600);
 

  //MOTOR1
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enablem1Pin3, OUTPUT);

  //MOTOR2
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enablem2Pin3, OUTPUT);

  //MOTOR3
  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(enablem3Pin3, OUTPUT);

  //MOTOR4
  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);
  pinMode(enablem4Pin3, OUTPUT);

  //Bluetooth state
 

}

void loop() {

  if (Serial.available() > 0) {
    serialA = Serial.read();
    Serial.println(serialA);
  }

  if (Serial.available() > 0) {
    state = Serial.read();
  }


  if (state == '0') {
    defaultSpeed = 0;
  }
  else if (state == '1') {
    defaultSpeed = 30;
  }
  else if (state == '2') {
    defaultSpeed = 60;
  }
  else if (state == '3') {
    defaultSpeed = 90;
  }
  else if (state == '4') {
    defaultSpeed = 120;
  }
  else if (state == '5') {
    defaultSpeed = 150;
  }
  else if (state == '6') {
    defaultSpeed = 180;
  }
  else if (state == '7') {
    defaultSpeed = 210;
  }
  else if (state == '8') {
    defaultSpeed = 240;
  }
  else if (state == '9') {
    defaultSpeed = 255;
  }
  Serial.print("DefaultSpeed: ");
  Serial.println(defaultSpeed);
  switch (serialA) {

    // forward
    case 'F':
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);

      digitalWrite(motor3Pin1, HIGH);
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, HIGH);
      digitalWrite(motor4Pin2, LOW);

      analogWrite(enablem1Pin3, defaultSpeed);
      analogWrite(enablem2Pin3, defaultSpeed);

      analogWrite(enablem3Pin3, defaultSpeed);
      analogWrite(enablem4Pin3, defaultSpeed);
      break;


    // left
    case 'L':
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);

      digitalWrite(motor3Pin1, LOW);
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, LOW);
      digitalWrite(motor4Pin2, HIGH);

      analogWrite(enablem1Pin3, defaultSpeed);
      analogWrite(enablem2Pin3, defaultSpeed);

      analogWrite(enablem3Pin3, defaultSpeed);
      analogWrite(enablem4Pin3, defaultSpeed);

      break;


    // right
    case 'R':




      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);

      digitalWrite(motor3Pin1, HIGH);
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, HIGH);
      digitalWrite(motor4Pin2, LOW);

      analogWrite(enablem1Pin3, defaultSpeed);
      analogWrite(enablem2Pin3, defaultSpeed);

      analogWrite(enablem3Pin3, defaultSpeed);
      analogWrite(enablem4Pin3, defaultSpeed);

      break;

    // forward left
    case 'G':
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);

      digitalWrite(motor3Pin1, HIGH);
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, HIGH);
      digitalWrite(motor4Pin2, LOW);

      analogWrite(enablem1Pin3, defaultSpeed);
      analogWrite(enablem2Pin3, defaultSpeed);

      analogWrite(enablem3Pin3, 20);
      analogWrite(enablem4Pin3, 20);
      break;


    // forward right
    case 'I':
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);

      digitalWrite(motor3Pin1, HIGH);
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, HIGH);
      digitalWrite(motor4Pin2, LOW);

      analogWrite(enablem1Pin3, 20);
      analogWrite(enablem2Pin3, 20);

      analogWrite(enablem3Pin3, defaultSpeed);
      analogWrite(enablem4Pin3, defaultSpeed);
      break;


    // backward left
    case 'H':
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);

      digitalWrite(motor3Pin1, LOW);
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, LOW);
      digitalWrite(motor4Pin2, HIGH);

      analogWrite(enablem1Pin3, defaultSpeed);
      analogWrite(enablem2Pin3, defaultSpeed);

      analogWrite(enablem3Pin3, 20);
      analogWrite(enablem4Pin3, 20);
      break;

    // backward right
    case 'J':
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);

      digitalWrite(motor3Pin1, LOW);
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, LOW);
      digitalWrite(motor4Pin2, HIGH);


      analogWrite(enablem1Pin3, 20);
      analogWrite(enablem2Pin3, 20);

      analogWrite(enablem3Pin3, defaultSpeed);
      analogWrite(enablem4Pin3, defaultSpeed);
      break;

    // backward
    case 'B':

      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);

      digitalWrite(motor3Pin1, LOW);
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, LOW);
      digitalWrite(motor4Pin2, HIGH);

      analogWrite(enablem1Pin3, defaultSpeed);
      analogWrite(enablem2Pin3, defaultSpeed);

      analogWrite(enablem3Pin3, defaultSpeed);
      analogWrite(enablem4Pin3, defaultSpeed);
      break;

    // Stop
    case 'S':
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor3Pin1, LOW);
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, LOW);
      digitalWrite(motor4Pin2, LOW);
      digitalWrite(enablem1Pin3, LOW);
      digitalWrite(enablem2Pin3, LOW);
      digitalWrite(enablem3Pin3, LOW);
      digitalWrite(enablem4Pin3, LOW);
  }
}
