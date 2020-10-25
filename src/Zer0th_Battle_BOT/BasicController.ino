const int chA = 8;
const int chB = 9;
const int chC = 10;
const int chD = 11;
const int chE = 12;
const int chF = 13;

int ch1;
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
void setup() {
  Serial.begin(9600);
  pinMode(chA, INPUT);
  pinMode(chB, INPUT);
  pinMode(chC, INPUT);
  pinMode(chD, INPUT);
  pinMode(chE, INPUT);
  pinMode(chF, INPUT);

}

void loop() {
  ch1 = pulseIn (chA, HIGH);
  ch2 = pulseIn (chB, HIGH);
  ch3 = pulseIn (chC, HIGH);
  ch4 = pulseIn (chD, HIGH);
  ch5 = pulseIn (chE, HIGH);
  ch6 = pulseIn (chF, HIGH);

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

  
}
