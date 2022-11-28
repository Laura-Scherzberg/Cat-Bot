/*
  Code Name: Arduino Bluetooth Car with Front and Back Light Control
  Code URI: https://circuitbest.com/category/arduino-projects/
  Before uploading the code you have to install the "Adafruit Motor Shield" library
  Open Arduino IDE >> Go to sketch >> Include Libray >> Manage Librays...  >> Search "Adafruit Motor Shield" >> Install the Library
  AFMotor Library: https://learn.adafruit.com/adafruit-motor-shield/library-install
  Author: Make DIY
  Author URI: https://circuitbest.com/author/admin/
  Description: This program is used to control a robot using an app that communicates with Arduino through an HC-05 Bluetooth Module.
  App URI: https://bit.ly/3mn6LuZ
  Version: 1.0
  License: Remixing or Changing this Thing is allowed. Commercial use is not allowed.
*/


#include <AFMotor.h>
#include <Wire.h>

#define SLAVE_ADDR 9
#define ANSWERSIZE 5
#define min_distance 50

//initial motors pins
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char val;
int Speeed = 220;
int randomNumber;
byte received_data;
int distance;

bool free_roam_mode = false;

void receiveCommand()
{
  if (Wire.available() > 0)
  {
    received_data = Wire.read();
  }
}

void controlled_movement() // modo telecomandado
{
  while (free_roam_mode == false)
  {
    if (Wire.available() > 0)
    {
      // recebe informações do master
      receiveCommand();
      val = received_data; // recebe character

      Stop(); //initialize with motors stoped

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
      if (val == 'S') {
        Stop();
      }
      if (val == 'C') {
        free_roam_mode = !free_roam_mode;
      }
    }
  }
}
void free_roam_movement() // modo free-roam
{
  while (free_roam_mode == true)
  {
    //distance sensor:
    if (Wire.available())
    {
      receiveCommand();
      distance = received_data; // recebe integer
    }

    if (distance <= min_distance)
    {
      randomNumber = random(1, 3);
      switch (randomNumber)
      {
        case 1: left(); delay(500); Stop(); break;
        case 2: right(); delay(500); Stop(); break;
        case 3: back(); delay(1500); Stop(); break;
      }
    }

    //free_roam:

    randomNumber = random(1, 6);
    switch (randomNumber)
    {
      case 1: left(); delay(500); Stop(); break;
      case 2: topleft(); delay(1000); Stop(); break;
      case 3: forward(); delay(1500); Stop(); break;
      case 4: topright(); delay(1000); Stop(); break;
      case 5: right(); delay(500); Stop(); break;
      case 6: Stop(); delay(1500); break;
    }

    if (Wire.available())
    {
      receiveCommand();
      val = received_data;
    }

    if (val == 'C') {
      free_roam_mode = !free_roam_mode;
    }
  }
}


void setup()
{
  Wire.begin(SLAVE_ADDR);
  Wire.onReceive(receiveCommand);

  randomSeed(analogRead(A0)); // for generating random numbers

}
void loop()
{
  if (free_roam_mode == false) // movimento controlado ativado
  {
    controlled_movement();
  }
  else if (free_roam_mode == true) // movimento livre ativado
  {
    free_roam_movement();
  }

}

void forward()
{
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(Speeed);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void topleft() {
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed / 3.1); //Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(Speeed / 3.1); //Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void topright()
{
  motor1.setSpeed(Speeed / 3.1); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed / 3.1); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(Speeed);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void bottomleft()
{
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed / 3.1); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed / 3.1); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void bottomright()
{
  motor1.setSpeed(Speeed / 3.1); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed / 3.1); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}


void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
