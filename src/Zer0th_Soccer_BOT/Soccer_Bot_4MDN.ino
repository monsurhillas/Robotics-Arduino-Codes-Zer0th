// Bluetooth RC Robot
// Programmed By NSU_Zer0th


//MOTOR1(DownLeft)
const int motor1Pin1 = 3;
const int motor1Pin2 = 2;
const int enablem1Pin3 = 5;

//MOTOR2
const int motor2Pin1 = 7;
const int motor2Pin2 = 4;
const int enablem2Pin3 = 6;

//MOTOR3
const int motor3Pin1 = 9;
const int motor3Pin2 = 8;
const int enablem3Pin3 = 10;

//MOTOR4
const int motor4Pin1 = 12;
const int motor4Pin2 = 13;
const int enablem4Pin3 = 11;

byte serialA;



void setup() {

  Serial.begin(9600);
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

}

void loop() {

  if (Serial.available() > 0) {
    serialA = Serial.read();
    Serial.println(serialA);
  }

  switch (serialA) {

    // forward
    case 'F':
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);

      digitalWrite(motor3Pin1, LOW);
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, LOW);
      digitalWrite(motor4Pin2, HIGH);

      analogWrite(enablem1Pin3, 220);//Downleft
      analogWrite(enablem2Pin3, 220);//Downright

      analogWrite(enablem3Pin3, 220);//upRight
      analogWrite(enablem4Pin3, 220);//upleft
      break;


    // left
    case 'L':
      digitalWrite(motor1Pin1, LOW);//DownLeft
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);//DOWNRight
      digitalWrite(motor2Pin2, HIGH);

      digitalWrite(motor3Pin1, HIGH);//UPRight
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, LOW);//upLeft
      digitalWrite(motor4Pin2, HIGH);

      analogWrite(enablem1Pin3, 190);
      analogWrite(enablem2Pin3, 190);

      analogWrite(enablem3Pin3, 190);
      analogWrite(enablem4Pin3, 190);

      break;


    // right
    case 'R':


      

        digitalWrite(motor1Pin1, HIGH);//DownLeft
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);//DOWNRight
      digitalWrite(motor2Pin2, LOW);

      digitalWrite(motor3Pin1, LOW);//UPLeft
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, HIGH);//UpRight
      digitalWrite(motor4Pin2, LOW);

      analogWrite(enablem1Pin3, 190);
      analogWrite(enablem2Pin3, 190);

      analogWrite(enablem3Pin3, 190);
      analogWrite(enablem4Pin3, 190);

      break;

    // forward left
    case 'G':
     digitalWrite(motor1Pin1, HIGH);//DownLeft
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);//DownRight
      digitalWrite(motor2Pin2, HIGH);

      digitalWrite(motor3Pin1, LOW);//UPLeft
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, LOW);//UpRight
      digitalWrite(motor4Pin2, HIGH);

        analogWrite(enablem1Pin3, 90);//Downleft
      analogWrite(enablem2Pin3, 220);//Downright

      analogWrite(enablem3Pin3, 220);//upRight
      analogWrite(enablem4Pin3, 90);//upleft
      break;


    // forward right
    case 'I':
       digitalWrite(motor1Pin1, HIGH);//DownLeft
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);//DownRight
      digitalWrite(motor2Pin2, HIGH);

      digitalWrite(motor3Pin1, LOW);//UPLeft
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, LOW);//UpRight
      digitalWrite(motor4Pin2, HIGH);

     analogWrite(enablem1Pin3, 220);//Downleft
      analogWrite(enablem2Pin3, 90);//Downright

      analogWrite(enablem3Pin3, 90);//upRight
      analogWrite(enablem4Pin3, 220);//upleft
      break;


    // backward left
    case 'H':
   digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);

      digitalWrite(motor3Pin1, HIGH);
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, HIGH);
      digitalWrite(motor4Pin2, LOW);

     analogWrite(enablem1Pin3, 90);//Downleft
      analogWrite(enablem2Pin3, 220);//Downright

      analogWrite(enablem3Pin3, 220);//upRight
      analogWrite(enablem4Pin3, 90);//upleft
      break;

    // backward right
    case 'J':
        digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);

      digitalWrite(motor3Pin1, HIGH);
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, HIGH);
      digitalWrite(motor4Pin2, LOW);

      analogWrite(enablem1Pin3, 220);//Downleft
      analogWrite(enablem2Pin3, 90);//Downright

      analogWrite(enablem3Pin3, 90);//upRight
      analogWrite(enablem4Pin3, 220);//upleft
      break;

    // backward
    case 'B':

     digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);

      digitalWrite(motor3Pin1, HIGH);
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, HIGH);
      digitalWrite(motor4Pin2, LOW);

      analogWrite(enablem1Pin3, 220);
      analogWrite(enablem2Pin3, 220);

      analogWrite(enablem3Pin3, 220);
      analogWrite(enablem4Pin3, 220);
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
