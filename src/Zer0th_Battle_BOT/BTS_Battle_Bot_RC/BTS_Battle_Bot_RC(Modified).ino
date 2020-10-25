const int chA = 14;
const int chB = 15;
const int chC = 16;
const int chD = 17;

int ch1 = 0;
int ch2 = 0;
int ch3 = 0;
int ch4 = 0;

//Motor1, Motor2
const int Left_Motor1_PWM = 11;
const int Left_Motor1_En = 12;

const int Left_Motor2_PWM = 10;
const int Left_Motor2_En = 13;

//Motor3, Motor4
const int Right_Motor1_PWM = 9;
const int Right_Motor1_En = 7;

const int Right_Motor2_PWM = 6;
const int Right_Motor2_En = 8;

//Fliper
const int Flip_M1 = 19;
const int Flip_M2 = 18;

void setup() {
  Serial.begin(9600);
  pinMode(chA, INPUT);
  pinMode(chB, INPUT);
  pinMode(chC, INPUT);
  pinMode(chD, INPUT);

  pinMode(Left_Motor1_PWM, OUTPUT);
  pinMode(Left_Motor1_En, OUTPUT);

  pinMode(Left_Motor2_PWM, OUTPUT);
  pinMode(Left_Motor2_En, OUTPUT);

  pinMode(Right_Motor1_PWM, OUTPUT);
  pinMode(Right_Motor1_En, OUTPUT);

  pinMode(Right_Motor2_PWM, OUTPUT);
  pinMode(Right_Motor2_En, OUTPUT);

  pinMode(Flip_M1, OUTPUT);
  pinMode(Flip_M2, OUTPUT);

  digitalWrite(Left_Motor1_En, HIGH);
  digitalWrite(Left_Motor2_En, HIGH);

  digitalWrite(Right_Motor1_En, HIGH);
  digitalWrite(Right_Motor2_En, HIGH);
}


void loop() {
  ch1 = pulseIn (chA, HIGH);
  ch2 = pulseIn (chB, HIGH);
  ch3 = pulseIn (chC, HIGH);
  ch4 = pulseIn (chD, HIGH);

  see_result();

  if (ch2 >= 1725 && ch2 < 1890)
  {
    //Front
    if (ch3 > 1625 && ch3 < 1850 && ch4 > 1350 && ch4 < 1674)
    {

      analogWrite(Left_Motor1_PWM, 255);
      analogWrite(Right_Motor1_PWM, 255);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);

    }

    //Back
    else if (ch3 < 1350 && ch3 > 1120 && ch4 > 1350 && ch4 < 1674)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 255);
      analogWrite(Left_Motor2_PWM, 255);

    }

    //Right
    else if (ch4 > 1675 && ch4 < 1890 && ch3 > 1375 && ch3 < 1600)
    {

      analogWrite(Left_Motor1_PWM, 220);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 220);
      digitalWrite(Left_Motor2_PWM, LOW);

    }

    //Left
    else if (ch4 < 1300 && ch4 > 1100 && ch3 > 1375 && ch3 < 1600)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      analogWrite(Right_Motor1_PWM, 220);

      digitalWrite(Right_Motor2_PWM, LOW);
      analogWrite(Left_Motor2_PWM, 220);

    }

    //ForwardRight
    else if (ch3 > 1601 && ch3 < 1850 && ch4 > 1675 && ch4 < 1950)
    {

      analogWrite(Left_Motor1_PWM, 255);
      analogWrite(Right_Motor1_PWM, 180);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);

    }

    //ForwardLeft
    else if (ch3 > 1601 && ch3 < 1850 && ch4 < 1349 && ch4 > 1050)
    {

      analogWrite(Left_Motor1_PWM, 180);
      analogWrite(Right_Motor1_PWM, 255);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);

    }

    //BackwardRight
    else if (ch3 < 1351 && ch3 > 1100 && ch4 > 1675 && ch4 < 1950)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 180);
      analogWrite(Left_Motor2_PWM, 255);

    }

    //BackwardLeft
    else if (ch3 < 1351 && ch3 > 1100 && ch4 < 1349 && ch4 > 1080)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 255);
      analogWrite(Left_Motor2_PWM, 180);

    }

    //Tham
    else
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);

    }
  }

  else if (ch2 < 1725 && ch2 >= 1375)
  {
    //Front
    if (ch3 > 1625 && ch3 < 1850 && ch4 > 1350 && ch4 < 1674)
    {

      analogWrite(Left_Motor1_PWM, 200);
      analogWrite(Right_Motor1_PWM, 200);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);

    }

    //Back
    else if (ch3 < 1350 && ch3 > 1120 && ch4 > 1350 && ch4 < 1674)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 200);
      analogWrite(Left_Motor2_PWM, 200);


    }

    //Right
    else if (ch4 > 1675 && ch4 < 1890 && ch3 > 1375 && ch3 < 1600)
    {

      analogWrite(Left_Motor1_PWM, 173);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 173);
      digitalWrite(Left_Motor2_PWM, LOW);

    }

    //Left
    else if (ch4 < 1300 && ch4 > 1100 && ch3 > 1375 && ch3 < 1600)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      analogWrite(Right_Motor1_PWM, 173);

      digitalWrite(Right_Motor2_PWM, LOW);
      analogWrite(Left_Motor2_PWM, 173);

    }

    //ForwardRight
    else if (ch3 > 1601 && ch3 < 1850 && ch4 > 1675 && ch4 < 1950)
    {

      analogWrite(Left_Motor1_PWM, 200);
      analogWrite(Right_Motor1_PWM, 142);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);

    }

    //ForwardLeft
    else if (ch3 > 1601 && ch3 < 1850 && ch4 < 1349 && ch4 > 1050)
    {

      analogWrite(Left_Motor1_PWM, 142);
      analogWrite(Right_Motor1_PWM, 200);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);

    }

    //BackwardRight
    else if (ch3 < 1351 && ch3 > 1100 && ch4 > 1675 && ch4 < 1950)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 142);
      analogWrite(Left_Motor2_PWM, 200);
    }

    //BackwardLeft
    else if (ch3 < 1351 && ch3 > 1100 && ch4 < 1349 && ch4 > 1080)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 200);
      analogWrite(Left_Motor2_PWM, 142);

    }

    //Tham
    else
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);

    }
  }

  else if (ch2 < 1375 && ch2 > 1150)
  {
    //Front
    if (ch3 > 1625 && ch3 < 1850 && ch4 > 1350 && ch4 < 1674)
    {

      analogWrite(Left_Motor1_PWM, 145);
      analogWrite(Right_Motor1_PWM, 145);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);

    }

    //Back
    else if (ch3 < 1350 && ch3 > 1120 && ch4 > 1350 && ch4 < 1674)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 145);
      analogWrite(Left_Motor2_PWM, 145);

    }

    //Right
    else if (ch4 > 1675 && ch4 < 1890 && ch3 > 1375 && ch3 < 1600)
    {

      analogWrite(Left_Motor1_PWM, 126);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 126);
      digitalWrite(Left_Motor2_PWM, LOW);

    }

    //Left
    else if (ch4 < 1300 && ch4 > 1100 && ch3 > 1375 && ch3 < 1600)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      analogWrite(Right_Motor1_PWM, 126);

      digitalWrite(Right_Motor2_PWM, LOW);
      analogWrite(Left_Motor2_PWM, 126);


    }

    //ForwardRight
    else if (ch3 > 1601 && ch3 < 1850 && ch4 > 1675 && ch4 < 1950)
    {

      analogWrite(Left_Motor1_PWM, 145);
      analogWrite(Right_Motor1_PWM, 103);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);

    }

    //ForwardLeft
    else if (ch3 > 1601 && ch3 < 1850 && ch4 < 1349 && ch4 > 1050)
    {

      analogWrite(Left_Motor1_PWM, 103);
      analogWrite(Right_Motor1_PWM, 145);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);
    }

    //BackwardRight
    else if (ch3 < 1351 && ch3 > 1100 && ch4 > 1675 && ch4 < 1950)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 103);
      analogWrite(Left_Motor2_PWM, 145);
    }

    //BackwardLeft
    else if (ch3 < 1351 && ch3 > 1100 && ch4 < 1349 && ch4 > 1080)
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      analogWrite(Right_Motor2_PWM, 145);
      analogWrite(Left_Motor2_PWM, 103);

    }

    //Tham
    else
    {

      digitalWrite(Left_Motor1_PWM, LOW);
      digitalWrite(Right_Motor1_PWM, LOW);

      digitalWrite(Right_Motor2_PWM, LOW);
      digitalWrite(Left_Motor2_PWM, LOW);

    }
  }


  if ( ch1 > 1700)
  {
    digitalWrite(Flip_M1, HIGH);
    digitalWrite(Flip_M2, LOW);
  }
  else if (ch1 < 1250)
  {
    digitalWrite(Flip_M1, LOW);
    digitalWrite(Flip_M2, HIGH);
  }
  else
  {
    digitalWrite(Flip_M1, LOW);
    digitalWrite(Flip_M2, LOW);
  }
}



void see_result() {

  Serial.print ("Ch1:");
  Serial.print (ch1);
  Serial.print ("|");

  Serial.print ("Ch2:");
  Serial.print (ch2);
  Serial.print ("|");

  Serial.print ("Ch3:");
  Serial.print (ch3);
  Serial.print ("|");

  Serial.print ("Ch4:");
  Serial.print (ch4);
  Serial.println ("|");

  //delay(1000);

}
