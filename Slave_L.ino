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
long espera;
long tempo=1000;

int ST = 220;  //VELOCIDADE TELECOMANDO
int SL = 190;  //velocidade com luz
int SF = 150;  //velocidade free roaming
int current_mode = 0;
int tele_mode = 1;
int free_mode = 2;
int luz_mode = 3;
int sleep_mode = 4;

int min_distance = 30;

void switch_mode(int v) {
  if (v == 'P') current_mode = 0;
  else if (v == 'W') current_mode = 1;
  else if (v == 'X') current_mode = 2;
  else if (v == 'Y') current_mode = 3;
  else if (v == 'Z') current_mode = 4;
}





void telecomando(int val) {

  Stop();  //initialize with motors stoped

  if (val == 'F') {
    forward(ST);
  }

  if (val == 'B') {
    back(ST);
  }

  if (val == 'L') {
    left(ST);
  }

  if (val == 'R') {
    right(ST);
  }
  if (val == 'I') {
    topright(ST);
  }

  if (val == 'J') {
    topleft(ST);
  }

  if (val == 'K') {
    bottomright(ST);
  }

  if (val == 'M') {
    bottomleft(ST);
  }
  if (val == 'T') {
    Stop();
  }
}


void forward(int Speeed) {
  Serial.println("forward");
  motor1.setSpeed(Speeed);  //Define maximum velocity
  motor1.run(FORWARD);      //rotate the motor clockwise
  motor2.setSpeed(Speeed);  //Define maximum velocity
  motor2.run(FORWARD);      //rotate the motor clockwise
  motor3.setSpeed(Speeed);  //Define maximum velocity
  motor3.run(FORWARD);      //rotate the motor clockwise
  motor4.setSpeed(Speeed);  //Define maximum velocity
  motor4.run(FORWARD);      //rotate the motor clockwise
}

void back(int Speeed) {
  Serial.println("back");
  motor1.setSpeed(Speeed);  //Define maximum velocity
  motor1.run(BACKWARD);     //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed);  //Define maximum velocity
  motor2.run(BACKWARD);     //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed);  //Define maximum velocity
  motor3.run(BACKWARD);     //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed);  //Define maximum velocity
  motor4.run(BACKWARD);     //rotate the motor anti-clockwise
}

void left(int Speeed) {
  Serial.println("left");
  motor1.setSpeed(Speeed);  //Define maximum velocity
  motor1.run(BACKWARD);     //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed);  //Define maximum velocity
  motor2.run(BACKWARD);     //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed);  //Define maximum velocity
  motor3.run(FORWARD);      //rotate the motor clockwise
  motor4.setSpeed(Speeed);  //Define maximum velocity
  motor4.run(FORWARD);      //rotate the motor clockwise
}

void right(int Speeed) {
  Serial.println("right");
  motor1.setSpeed(Speeed);  //Define maximum velocity
  motor1.run(FORWARD);      //rotate the motor clockwise
  motor2.setSpeed(Speeed);  //Define maximum velocity
  motor2.run(FORWARD);      //rotate the motor clockwise
  motor3.setSpeed(Speeed);  //Define maximum velocity
  motor3.run(BACKWARD);     //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed);  //Define maximum velocity
  motor4.run(BACKWARD);     //rotate the motor anti-clockwise
}

void topleft(int Speeed) {
  Serial.println("topleft");
  motor1.setSpeed(Speeed);        //Define maximum velocity
  motor1.run(FORWARD);            //rotate the motor clockwise
  motor2.setSpeed(Speeed);        //Define maximum velocity
  motor2.run(FORWARD);            //rotate the motor clockwise
  motor3.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor3.run(FORWARD);            //rotate the motor clockwise
  motor4.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor4.run(FORWARD);            //rotate the motor clockwise
}

void topright(int Speeed) {
  Serial.println("topright");
  motor1.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor1.run(FORWARD);            //rotate the motor clockwise
  motor2.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor2.run(FORWARD);            //rotate the motor clockwise
  motor3.setSpeed(Speeed);        //Define maximum velocity
  motor3.run(FORWARD);            //rotate the motor clockwise
  motor4.setSpeed(Speeed);        //Define maximum velocity
  motor4.run(FORWARD);            //rotate the motor clockwise
}

void bottomleft(int Speeed) {
  Serial.println("bottomleft");
  motor1.setSpeed(Speeed);        //Define maximum velocity
  motor1.run(BACKWARD);           //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed);        //Define maximum velocity
  motor2.run(BACKWARD);           //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor3.run(BACKWARD);           //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed / 3.1);  //Define maximum velocity
  motor4.run(BACKWARD);           //rotate the motor anti-clockwise
}

void bottomright(int Speeed) {
  Serial.println("bottomright");
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
  Stop();  //inicializa com motores parados
  //Serial.print("LSensor");
  //Serial.println(LSensor);
  //Serial.print("MSensor");
  // Serial.println(MSensor);
  //  Serial.print("RSensor");
  //  Serial.println(RSensor);

  if (((LSensor == 0) && (MSensor == 0) && (RSensor == 0)) || ((LSensor == 1) && (MSensor == 0) && (RSensor == 1))) {
    //MOVE FORWARD
    forward(SL);

  } else if ((LSensor == 0) && (RSensor == 1)) {
    //TURN LEFT
    left(SL);

  } else if ((LSensor == 1) && (RSensor == 0)) {
    //TURN RIGHT
    right(SL);
  } else if (((LSensor == 1) && (MSensor == 1) && (RSensor == 1))) {
    Stop();
  }
}

void free_roam(int distance)  // modo free-roam
{
  espera=millis();
  
  Stop(); //inicia com os motores parados
  Serial.print("distance:");
  Serial.println(distance);
  int randomNumber;
  if (distance <= min_distance) {
    Serial.println("demasiado perto");
    back(SF);
    /*randomNumber = random(1, 4);
    switch (randomNumber) {
      case 1:
        back(SF);
      //  delay(500);
       // Stop();
        break;
      case 2:
        right(SF);
       // delay(500);
       // Stop();
        break;
      case 3:
        left(SF);
      //  delay(1500);
       // Stop();
        break;
    }*/
  }

  //free_roam:
else{
  randomNumber = random(1, 7);
  switch (randomNumber) {
    case 1:
      left(SF);
     // delay(500);
     // Stop();
      break;
    case 2:
      topleft(SF);
    //  delay(1000);
    //  Stop();
      break;
    case 3:
      forward(SF);
     // delay(1500);
     // Stop();
      break;
    case 4:
      topright(SF);
    //  delay(1000);
    //  Stop();
      break;
    case 5:
      right(SF);
    //  delay(500);
    //  Stop();
      break;
    case 6:
      Stop();
     // delay(1500);
      break;
  }
}
}


void data(int val) {
  if (Wire.available() > 0) {
    val = Wire.read();
    Serial.println(val);
  }
  switch_mode(val);  //verifica o modo

  //o que tem de fazer consoante o modo
  if (current_mode == 0) Serial.print("nada");
  else if (current_mode == tele_mode) telecomando(val);
  else if (current_mode == free_mode&&(millis()-espera>=tempo || val<min_distance)) free_roam(val);  //free roaming faz a cada x tempo ou quando a distancia é pequena
  else if (current_mode == sleep_mode) Serial.print("sleep");  //sleep
}


void setup() {
  Wire.begin(SLAVE_ADDR);
  Wire.onReceive(data);
  Serial.begin(9600);
  pinMode(L1, INPUT);
  pinMode(M1, INPUT);
  pinMode(R1, INPUT);
  randomSeed(analogRead(A0));  // for generating random numbers
  espera=millis();
}

void loop() {
  delay(50);
  if (current_mode == 0) Stop();        // luz
  if (current_mode == luz_mode) luz();  // luz
  
}
