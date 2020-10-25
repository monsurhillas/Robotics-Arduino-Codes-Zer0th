const int chA = 10;
const int chB = 11;
const int chC = 12;
const int chD = 13;

int ch1;
int ch2;
int ch3;
int ch4;

//Motor1
const int Left1_M1 = 0;
const int Left1_M2 = 1;

//Motor2
const int Left2_M1 = 2;
const int Left2_M2 = 3;

//Motor3
const int Right1_M1 = 4;
const int Right1_M2 = 5;

//Motor4
const int Right2_M1 = 6;
const int Right2_M2 = 7;

//Fliper
const int Flip_M1 = 8;
const int Flip_M2 = 9;


void setup() {
  Serial.begin(9600);
  pinMode(chA, INPUT);
  pinMode(chB, INPUT);
  pinMode(chC, INPUT);
  pinMode(chD, INPUT);
  
  pinMode(Left1_M1, OUTPUT);
  pinMode(Left1_M2, OUTPUT);

  pinMode(Left2_M1, OUTPUT);
  pinMode(Left2_M2, OUTPUT);
  
  pinMode(Right1_M1, OUTPUT);
  pinMode(Right1_M2, OUTPUT);

  pinMode(Right2_M1, OUTPUT);
  pinMode(Right2_M2, OUTPUT);
  
  pinMode(Flip_M1, OUTPUT);
  pinMode(Flip_M2, OUTPUT);
}


void loop() {
  ch1 = pulseIn (chA, HIGH);
  ch2 = pulseIn (chB, HIGH);
  ch3 = pulseIn (chC, HIGH);
  ch4 = pulseIn (chD, HIGH);

  see_result();

  if (ch3 > 1650 && ch4 > 1375 && ch4 < 1525) {
    front();
  }

  else if (ch3 < 1350 && ch4 > 1375 && ch4 < 1525) {
    back();
  }

  else if (ch4 > 1600 && ch3 > 1350 && ch3 < 1550) {
    right();
  }

  else if (ch4 < 1300 && ch3 > 1350 && ch3 < 1550) {
    left();
  }

  else if (ch3 > 1650 && ch4 < 1225) {
    frontleft();
  }

  else if (ch3 > 1650 && ch4 > 1600) {
    frontright();
  }

  else {
    tham();
  }


  if ( ch3 > 1700) {
    Flip_UP();
  }
  else if (ch3 < 1250) {
    Flip_Down();
  }
  else {
    Flip_tham();
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
  Serial.print (ch1);
  Serial.println ("|");

  delay(1000);
}

void front() {
  digitalWrite(Left1_M1, HIGH);
  digitalWrite(Left1_M2, LOW);
  
  digitalWrite(Left2_M1, HIGH);
  digitalWrite(Left2_M2, LOW);
  
  digitalWrite(Right1_M1, HIGH);
  digitalWrite(Right1_M2, LOW);
  
  digitalWrite(Right2_M1, HIGH);
  digitalWrite(Right2_M2, LOW);
}


void back() {
  digitalWrite(Left1_M1, LOW);
  digitalWrite(Left1_M2, HIGH);

  digitalWrite(Left2_M1, LOW);
  digitalWrite(Left2_M2, HIGH);
  
  digitalWrite(Right1_M1, LOW);
  digitalWrite(Right1_M2, HIGH);

  digitalWrite(Right2_M1, LOW);
  digitalWrite(Right2_M2, HIGH);
}

void frontleft() {
  digitalWrite(Left1_M1, HIGH);
  digitalWrite(Left1_M2, LOW);
  
  digitalWrite(Left2_M1, HIGH);
  digitalWrite(Left2_M2, LOW);
  
  digitalWrite(Right1_M1, LOW);
  digitalWrite(Right1_M2, LOW);
  
  digitalWrite(Right2_M1, LOW);
  digitalWrite(Right2_M2, LOW);
}

void frontright() {
  digitalWrite(Left1_M1, LOW);
  digitalWrite(Left1_M2, LOW);
  
  digitalWrite(Left2_M1, LOW);
  digitalWrite(Left2_M2, LOW);
  
  digitalWrite(Right1_M1, HIGH);
  digitalWrite(Right1_M2, LOW);
  
  digitalWrite(Right2_M1, HIGH);
  digitalWrite(Right2_M2, LOW);
}

void backleft() {
  digitalWrite(Left1_M1, LOW);
  digitalWrite(Left1_M2, HIGH);
  
  digitalWrite(Left2_M1, LOW);
  digitalWrite(Left2_M2, HIGH);
  
  digitalWrite(Right1_M1, LOW);
  digitalWrite(Right1_M2, LOW);
  
  digitalWrite(Right2_M1, LOW);
  digitalWrite(Right2_M2, LOW);
}

void backright() {
  digitalWrite(Left1_M1, LOW);
  digitalWrite(Left1_M2, LOW);
  
  digitalWrite(Left2_M1, LOW);
  digitalWrite(Left2_M2, LOW);
  
  digitalWrite(Right1_M1, LOW);
  digitalWrite(Right1_M2, HIGH);
  
  digitalWrite(Right2_M1, LOW);
  digitalWrite(Right2_M2, HIGH);
}

void left() {
  digitalWrite(Left1_M1, HIGH);
  digitalWrite(Left1_M2, LOW);

  digitalWrite(Left2_M1, HIGH);
  digitalWrite(Left2_M2, LOW);
  
  digitalWrite(Right1_M1, LOW);
  digitalWrite(Right1_M2, HIGH);

  digitalWrite(Right2_M1, LOW);
  digitalWrite(Right2_M2, HIGH);
}

void right() {
  digitalWrite(Left1_M1, LOW);
  digitalWrite(Left1_M2, HIGH);

  digitalWrite(Left2_M1, LOW);
  digitalWrite(Left2_M2, HIGH);
  
  digitalWrite(Right1_M1, HIGH);
  digitalWrite(Right1_M2, LOW);

  digitalWrite(Right2_M1, HIGH);
  digitalWrite(Right2_M2, LOW);
}

void tham() {
  digitalWrite(Left1_M1, LOW);
  digitalWrite(Left1_M2, LOW);

  digitalWrite(Left2_M1, LOW);
  digitalWrite(Left2_M2, LOW);
  
  digitalWrite(Right1_M1, LOW);
  digitalWrite(Right1_M2, LOW);

  digitalWrite(Right2_M1, LOW);
  digitalWrite(Right2_M2, LOW);
}

void Flip_UP() {
  digitalWrite(Flip_M1, HIGH);
  digitalWrite(Flip_M2, LOW);
}

void Flip_Down() {
  digitalWrite(Flip_M1, LOW);
  digitalWrite(Flip_M2, HIGH);
}

void Flip_tham() {
  digitalWrite(Flip_M1, LOW);
  digitalWrite(Flip_M2, LOW);
}
