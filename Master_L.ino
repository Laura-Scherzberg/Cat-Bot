#include <Wire.h>
#define SLAVE_ADDR 9
int val;
int current_mode = 0;
int tele_mode = 1;
int free_mode = 2;
int luz_mode = 3;
int sleep_mode = 4;

#define trigPin 8
#define echoPin 9

long espera;
long tempo=1000;


long measureDistance(){
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); //converte para int

  distance = duration / 58;
  Serial.print("distance measured:");
  Serial.println(distance);
  if(distance>75) return 70;
  else return distance;
}

void switch_mode(int val) {
 // Serial.println("switch");
  if (val == 'P') {
    current_mode = 0;
  }
  else if (val == 'W') {
    current_mode = 1;
  }
  else if (val == 'X') {
    current_mode = 2;
  }
  else if (val == 'Y') {
    current_mode = 3;
  }
  else if (val == 'Z') {
    current_mode = 4;
  }

}

/*void telecomando() {
  Serial.println(val);
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(val);
  Wire.endTransmission();

}

void nada() {
  int nope = 'P';
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(nope);
  Wire.endTransmission();
}
*/

void setup() {
  Wire.begin();
  Serial.begin(9600);
  randomSeed(analogRead(A0)); // for generating random numbers

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  espera=millis();
}

void loop() {
   if (Serial.available() > 0) // lê do bluetooth
  {
    Serial.print("val");
    val = Serial.read();
    delay(50);
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(val);
    Wire.endTransmission();
    switch_mode(val);
  }
  if(current_mode==free_mode/*&&millis()-espera>=tempo*/){ 
    int dis = (int) measureDistance();
    Serial.println(dis);
    delay(50);
    Wire.beginTransmission(SLAVE_ADDR);   
    Wire.write(dis);
    Wire.endTransmission();

    espera=millis();
  }

}
