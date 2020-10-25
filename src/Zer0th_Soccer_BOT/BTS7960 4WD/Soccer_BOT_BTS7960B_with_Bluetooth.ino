// Bluetooth RC Robot
// Programmed By NSU_Zer0th

//Left Side Motor Pins for BTS7960B --------------
int LPWM1 = 10; //for Motor 1,2
int enL1 = 12; 

int RPWM1 = 11; 
int enR1 = 13; 

int LPWM2 = 5 ; //for Motor 3,4
int enL2 = 7;

int RPWM2 = 6;
int enR2 = 8;
//-------------------------------------------------



//Speed Section --------
int defaultSpeed = 255;
//----------------------
int state;
//Bluetooth section-----
byte serialA;
//----------------------


void setup()
{
  Serial.begin (9600); //initializer for arduino
  //pinMode Definitions ------------------------ 
  pinMode(LPWM1, OUTPUT); //for Motor 1,2
  pinMode(RPWM1, OUTPUT);
  pinMode(enL1, OUTPUT);
  pinMode(enR1, OUTPUT);


  pinMode(LPWM2, OUTPUT); //for Motor 3,4
  pinMode(RPWM2, OUTPUT);
  pinMode(enL2, OUTPUT);
  pinMode(enR2, OUTPUT);


  
  //--------------------------------------------
  
  //Setting enables HIGH -----------------------
  digitalWrite(enL1, HIGH); //for Motor 1,2
  digitalWrite(enR1, HIGH);

  digitalWrite(enL2,HIGH); //for Motor 3,4
  digitalWrite(enR2,HIGH);
  //--------------------------------------------
}

void loop()
{
  if (Serial.available() > 0) 
  {
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

    //----Front----
    case 'F':

    analogWrite(RPWM1,defaultSpeed); //pwm value 1,2
    digitalWrite(LPWM1,LOW);

    digitalWrite(RPWM2,LOW); //pwm value 3,4
    analogWrite(LPWM2,defaultSpeed);
    break;


    //---- Back ----
    case 'B':

    digitalWrite(RPWM1,LOW); //pwm value 1,2
    analogWrite(LPWM1,defaultSpeed);

    analogWrite(RPWM2,defaultSpeed); //pwm value 3,4
    digitalWrite(LPWM2,LOW);
    break;

     
     
     //---- Right ----
    case 'R':
  
    digitalWrite(RPWM1,LOW); //pwm value 1,2
    analogWrite(LPWM1,defaultSpeed);

    digitalWrite(RPWM2,LOW); //pwm value 3,4
    analogWrite(LPWM2,defaultSpeed);
    break;



    //---- Left ----
    
    case 'L':
    analogWrite(RPWM1,defaultSpeed); //pwm value 1,2
    digitalWrite(LPWM1, LOW);

    analogWrite(RPWM2,defaultSpeed); //pwm value 3,4
    digitalWrite(LPWM2,LOW);
    break;

    //---- Forward-Left ----
    case 'G':
    analogWrite(RPWM1,defaultSpeed); //pwm value 1,2
    digitalWrite(LPWM1,LOW);

    digitalWrite(RPWM2,LOW); //pwm value 3,4
    analogWrite(LPWM2,80);
    break;

    //---- Forward-Right ----
     case 'I':
     analogWrite(RPWM1,80); //pwm value 1,2
    digitalWrite(LPWM1,LOW);

    digitalWrite(RPWM2,LOW); //pwm value 3,4
    analogWrite(LPWM2,defaultSpeed);
    break;

    //---- Backward-Left ----
    case 'H':
    digitalWrite(RPWM1,LOW); //pwm value 1,2
    analogWrite(LPWM1,defaultSpeed);

    analogWrite(RPWM2,80); //pwm value 3,4
    digitalWrite(LPWM2,LOW);
    break;

    //---- Backward-Right ----
    case 'J':
    digitalWrite(RPWM1,LOW); //pwm value 1,2
    analogWrite(LPWM1,80);

    analogWrite(RPWM2,defaultSpeed); //pwm value 3,4
    digitalWrite(LPWM2,LOW);
    break;

     
    //---- Stop ----
    case 'S':
    digitalWrite(RPWM1,LOW); //pwm value 1,2
    digitalWrite(LPWM1,LOW);

    digitalWrite(RPWM2,LOW); //pwm value 3,4
    digitalWrite(LPWM2,LOW);
    break;
  }

}
