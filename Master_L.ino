#include <Wire.h>
#define SLAVE_ADDR 9
int val;
int current_mode = 0;
int tele_mode = 1;
int free_mode = 2;
int luz_mode = 3;
int sleep_mode = 4;

void switch_mode() {
 // Serial.println("switch");
  if (val == 'P') {
    current_mode = 0;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(val);
    Wire.endTransmission();
  }
  else if (val == 'W') {
    current_mode = 1;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(val);
    Wire.endTransmission();
  }
  else if (val == 'X') {
    current_mode = 2;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(val);
    Wire.endTransmission();
  }
  else if (val == 'Y') {
    current_mode = 3;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(val);
    Wire.endTransmission();
  }
  else if (val == 'Z') {
    current_mode = 4;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(val);
    Wire.endTransmission();
  }

}

void telecomando() {
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

void setup() {
  Wire.begin();
  Serial.begin(9600);
pinMode(LED_BUILTIN, OUTPUT);
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
  }

// if (Serial.available() > 0) {
//   val = Serial.read();  
//   //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//   } telecomando();  
   
    //o que tem de fazer consoante o modo
//    delay(50);
//    switch_mode();
//    if (current_mode == tele_mode) telecomando();
//    else if (current_mode == free_mode) ;   //free roaming
//    else if (current_mode == luz_mode) ;    // luz
//    else if (current_mode == sleep_mode) ;  //sleep
//   }   

}
