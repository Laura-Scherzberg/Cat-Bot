#include <AFMotor.h>
#include <Wire.h>
#define SLAVE_ADDR 9
#define L1 A0
#define M1 A1
#define R1 A2
//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


int Speeed = 220;
int current_mode = 0;
int tele_mode = 1;
int free_mode = 2;
int luz_mode = 3;
int sleep_mode = 4;


void switch_mode(int v) {
  Serial.println(current_mode);
  if (v == 'P') current_mode = 0;
  else if (v == 'W') current_mode = 1;
  else if (v == 'X') current_mode = 2;
  else if (v == 'Y') current_mode = 3;
  else if (v == 'Z') current_mode = 4;
}





void telecomando(int val) {

  Stop();  //initialize with motors stoped

  if (val == 'F') {
    forward();
  }

  if (val == 'B') {
    back();
  }

  if (val == 'L') {
    left();
  }

  if (val == 'R') {
    right();
  }
  if (val == 'I') {
    topright();
  }

  if (val == 'J') {
    topleft();
  }

  if (val == 'K') {
    bottomright();
  }

  if (val == 'M') {
    bottomleft();
  }
  if (val == 'T') {
    Stop();
  }
}


void forward() {
  Serial.println("f");
  motor1.setSpeed(Speeed);  //Define maximum velocity
  motor1.run(FORWARD);      //rotate the motor clockwise
  motor2.setSpeed(Speeed);  //Define maximum velocity
  motor2.run(FORWARD);      //rotate the motor clockwise
  motor3.setSpeed(Speeed);  //Define maximum velocity
  motor3.run(FORWARD);      //rotate the motor clockwise
  motor4.setSpeed(Speeed);  //Define maximum velocity
  motor4.run(FORWARD);      //rotate the motor clockwise
}

void back() {
  motor1.setSpeed(Speeed);  //Define maximum velocity
  motor1.run(BACKWARD);     //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed);  //Define maximum velocity
  motor2.run(BACKWARD);     //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed);  //Define maximum velocity
  motor3.run(BACKWARD);     //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed);  //Define maximum velocity
  motor4.run(BACKWARD);     //rotate the motor anti-clockwise
}

void left() {
  motor1.setSpeed(Speeed);  //Define maximum velocity
  motor1.run(BACKWARD);     //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed);  //Define maximum velocity
  motor2.run(BACKWARD);     //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed);  //Define maximum velocity
  motor3.run(FORWARD);      //rotate the motor clockwise
  motor4.setSpeed(Speeed);  //Define maximum velocity
  motor4.run(FORWARD);      //rotate the motor clockwise
}

void right() {
  motor1.setSpeed(Speeed);  //Define maximum velocity
  motor1.run(FORWARD);      //rotate the motor clockwise
  motor2.setSpeed(Speeed);  //Define maximum velocity
  motor2.run(FORWARD);      //rotate the motor clockwise
  motor3.setSpeed(Speeed);  //Define maximum velocity
  motor3.run(BACKWARD);     //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed);  //Define maximum velocity
  motor4.run(BACKWARD);     //rotate the motor anti-clockwise
}

void topleft() {
  motor1.setSpeed(Speeed);        //Define maximum velocity
  motor1.run(FORWARD);            //rotate the motor clockwise
  motor2.setSpeed(Speeed);        //Define maximum velocity
  motor2.run(FORWARD);            //rotate the motor clockwise
  motor3.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor3.run(FORWARD);            //rotate the motor clockwise
  motor4.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor4.run(FORWARD);            //rotate the motor clockwise
}

void topright() {
  motor1.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor1.run(FORWARD);            //rotate the motor clockwise
  motor2.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor2.run(FORWARD);            //rotate the motor clockwise
  motor3.setSpeed(Speeed);        //Define maximum velocity
  motor3.run(FORWARD);            //rotate the motor clockwise
  motor4.setSpeed(Speeed);        //Define maximum velocity
  motor4.run(FORWARD);            //rotate the motor clockwise
}

void bottomleft() {
  motor1.setSpeed(Speeed);        //Define maximum velocity
  motor1.run(BACKWARD);           //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed);        //Define maximum velocity
  motor2.run(BACKWARD);           //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor3.run(BACKWARD);           //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor4.run(BACKWARD);           //rotate the motor anti-clockwise
}

void bottomright() {
  motor1.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor1.run(BACKWARD);           //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor2.run(BACKWARD);           //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed);        //Define maximum velocity
  motor3.run(BACKWARD);           //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed);        //Define maximum velocity
  motor4.run(BACKWARD);           //rotate the motor anti-clockwise
}


void Stop() {
  motor1.setSpeed(0);   //Define minimum velocity
  motor1.run(RELEASE);  //stop the motor when release the button
  motor2.setSpeed(0);   //Define minimum velocity
  motor2.run(RELEASE);  //rotate the motor clockwise
  motor3.setSpeed(0);   //Define minimum velocity
  motor3.run(RELEASE);  //stop the motor when release the button
  motor4.setSpeed(0);   //Define minimum velocity
  motor4.run(RELEASE);  //stop the motor when release the button
}

void luz() {
  int LSensor = digitalRead(L1);
  int MSensor = digitalRead(M1);
  int RSensor = digitalRead(R1);
  Stop();//inicializa com motores parados
  //Serial.print("LSensor");
  //Serial.println(LSensor);
  Serial.print("MSensor");
  Serial.println(MSensor);
//  Serial.print("RSensor");
//  Serial.println(RSensor);

  if (((LSensor == 0) && (MSensor == 0) && (RSensor == 0))||((LSensor == 1) && (MSensor == 0) && (RSensor == 1))) {
    //MOVE FORWARD
    Serial.println("forward");
    forward();

  } else if ((LSensor == 0) && (RSensor == 1)) {
    //TURN LEFT
    left();

  } else if ((LSensor == 1) && (RSensor == 0)) {
    //TURN RIGHT
    right();
  } else if (((LSensor == 1) && (MSensor == 1) && (RSensor == 1))) {
    Stop();
  }
}

void data(int val) {
  if (Wire.available() > 0) {
    val = Wire.read();
    Serial.println(val);
  }
  switch_mode(val); //verifica o modo

  //o que tem de fazer consoante o modo
  if (current_mode == 0) Serial.print("nada");
  else if (current_mode == tele_mode) telecomando(val);
  else if (current_mode == free_mode) Serial.print("free");  //free roaming
  
  else if (current_mode == sleep_mode) Serial.print("sleep");  //sleep
}


void setup() {
  Wire.begin(SLAVE_ADDR);
  Wire.onReceive(data);
  Serial.begin(9600);
  pinMode(L1, INPUT);
  pinMode(M1, INPUT);
  pinMode(R1, INPUT);
}

void loop() {
  delay(50);
  if (current_mode == 0) Stop();  // luz
  if (current_mode == luz_mode) luz();  // luz
}
