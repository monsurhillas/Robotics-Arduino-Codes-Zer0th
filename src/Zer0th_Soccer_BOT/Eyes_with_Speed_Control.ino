// Bluetooth RC Robot
// Programmed By NSU_Zer0th

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

int LPWM1 = 3; //for Motor 1,2
int enL1 = 2;

int RPWM1 = 5;
int enR1 = 4;

int LPWM2 = 6; //for Motor 3,4
int enL2 = 7;

int RPWM2 = 9;
int enR2 = 8;

//EYES------------------
const int leftEye = 17;
const int rightEye = 18;

//Useful Variables
int i = 0;
int j = 0;
//----------------------
int state;
//----------------------

//Speed Section --------
int defaultSpeed = 255;
//----------------------

//Bluetooth section-----
byte serialA;
//----------------------

void setup() {
  Serial.begin (9600); //initializer for arduino
  mySerial.begin(9600);
  //pinMode Definitions ------------------------
  pinMode(LPWM1, OUTPUT); //for Motor 1,2
  pinMode(RPWM1, OUTPUT);
  pinMode(enL1, OUTPUT);
  pinMode(enR1, OUTPUT);


  pinMode(LPWM2, OUTPUT); //for Motor 3,4
  pinMode(RPWM2, OUTPUT);
  pinMode(enL2, OUTPUT);
  pinMode(enR2, OUTPUT);

  pinMode(leftEye, OUTPUT);
  pinMode(rightEye, OUTPUT);

  //--------------------------------------------

  //Setting enables HIGH -----------------------
  digitalWrite(enL1, HIGH); //for Motor 1,2
  digitalWrite(enR1, HIGH);

  digitalWrite(enL2, HIGH); //for Motor 3,4
  digitalWrite(enR2, HIGH);
  //--------------------------------------------
}

void loop() {

  //Bluetooth available-------------------------
  if (mySerial.available() > 0) {
    serialA = mySerial.read();
    Serial.println(serialA);
  }
  //--------------------------------------------

  //Save income data to variable 'state'--------
  if (mySerial.available() > 0) {
    state = mySerial.read();
  }
  //--------------------------------------------

  //Speed Control-------------------------------
  if (state == '0') {
    defaultSpeed = 85;
  }
  else if (state == '1') {
    defaultSpeed = 85;
  }
  else if (state == '2') {
    defaultSpeed = 85;
  }
  else if (state == '3') {
    defaultSpeed = 150;
  }
  else if (state == '4') {
    defaultSpeed = 150;
  }
  else if (state == '5') {
    defaultSpeed = 150;
  }
  else if (state == '6') {
    defaultSpeed = 255;
  }
  else if (state == '7') {
    defaultSpeed = 255;
  }
  else if (state == '8') {
    defaultSpeed = 255;
  }
  else if (state == '9') {
    defaultSpeed = 255;
  }
  Serial.print("DefaultSpeed: ");
  Serial.println(defaultSpeed);
  //--------------------------------------------

  //Forward----------------------------------------------------
  //If state is equal with letter 'F', car will go forward!
  if (state == 'F') {
    Serial.println("F");
    analogWrite(RPWM1, defaultSpeed); //pwm value 1,2
    digitalWrite(LPWM1, LOW);

    analogWrite(RPWM2, defaultSpeed); //pwm value 3,4
    digitalWrite(LPWM2, LOW);
  }
  
  //Forward Left-----------------------------------------------
  //If state is equal with letter 'G', car will go forward left
  else if (state == 'G') {
    Serial.println("FL");
    analogWrite(RPWM1, 80); //pwm value 1,2
    digitalWrite(LPWM1, LOW);

    analogWrite(RPWM2, defaultSpeed); //pwm value 3,4
    digitalWrite(LPWM2, LOW);
  }
  
  //Forward Right----------------------------------------------
  //If state is equal with letter 'I', car will go forward right
  else if (state == 'I') {
    Serial.println("FR");
    analogWrite(RPWM1, defaultSpeed); //pwm value 1,2
    digitalWrite(LPWM1, LOW);

    analogWrite(RPWM2, 80); //pwm value 3,4
    digitalWrite(LPWM2, LOW);
  }
  
  //Backward---------------------------------------------------
  //If state is equal with letter 'B', car will go backward
  else if (state == 'B') {
    Serial.println("B");
    digitalWrite(RPWM1, LOW); //pwm value 1,2
    analogWrite(LPWM1, defaultSpeed);

    digitalWrite(RPWM2, LOW); //pwm value 3,4
    analogWrite(LPWM2, defaultSpeed);
  }
  
  //Backward Left----------------------------------------------
  //If state is equal with letter 'H', car will go backward left
  else if (state == 'H') {
    Serial.println("BL");
    digitalWrite(RPWM1, LOW); //pwm value 1,2
    analogWrite(LPWM1, 80);

    digitalWrite(RPWM2, LOW); //pwm value 3,4
    analogWrite(LPWM2, defaultSpeed);
  }
  
  //Backward Right---------------------------------------------
  //If state is equal with letter 'J', car will go backward right
  else if (state == 'J') {
    Serial.println("BR");
    digitalWrite(RPWM1, LOW); //pwm value 1,2
    analogWrite(LPWM1, defaultSpeed);

    digitalWrite(RPWM2, LOW); //pwm value 3,4
    analogWrite(LPWM2, 80);
  }
  
  //Left-------------------------------------------------------
  //If state is equal with letter 'L', wheels will turn left
  else if (state == 'L') {
    Serial.println("L");
    digitalWrite(RPWM1, LOW); //pwm value 1,2
    analogWrite(LPWM1, defaultSpeed);

    analogWrite(RPWM2, defaultSpeed); //pwm value 3,4
    digitalWrite(LPWM2, LOW);
  }
  
  //Right------------------------------------------------------
  //If state is equal with letter 'R', wheels will turn right
  else if (state == 'R') {
    Serial.println("R");
    analogWrite(RPWM1, defaultSpeed); //pwm value 1,2
    digitalWrite(LPWM1, LOW);

    digitalWrite(RPWM2, LOW); //pwm value 3,4
    analogWrite(LPWM2, defaultSpeed);
  }
  
  //Eyes----------------------------------------------------
  //If state is equal with letter 'W', turn Eyes on or off
  else if (state == 'W') {
    if (i == 0) {
      Serial.println("EYE_ON");
      digitalWrite(leftEye, HIGH);
      digitalWrite(rightEye, HIGH);
      i = 1;
    }
    else if (i == 1) {
      Serial.println("EYE_OFF");
      digitalWrite(leftEye, LOW);
      digitalWrite(rightEye, LOW);
      i = 0;
    }
    state = 'n';
  }
  
  //Eyes Blink------------------------------------------------
  //If state is equal with letter 'X', turn Eyes Blink on or off
  else if (state == 'X') {
    if (j == 0) {
      for (int k = 0; k < 5; k++)
      {
        digitalWrite(leftEye, HIGH);
        digitalWrite(rightEye, HIGH);
        delay(200);
        digitalWrite(leftEye, LOW);
        digitalWrite(rightEye, LOW);
        delay(200);
      }
      j = 1;
    }
    else if (j == 1) {
      digitalWrite(leftEye, LOW);
      digitalWrite(rightEye, LOW);

      j = 0;
    }
    state = 'n';
  }
  
  //Stop------------------------------------------------------
  //If state is equal with letter 'S', stop the car
  else if (state == 'S') {
    digitalWrite(RPWM1, LOW); //pwm value 1,2
    digitalWrite(LPWM1, LOW);

    digitalWrite(RPWM2, LOW); //pwm value 3,4
    digitalWrite(LPWM2, LOW);
  }
}
