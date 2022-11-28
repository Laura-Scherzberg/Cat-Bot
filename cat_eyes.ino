#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte closed_eyes_top[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111
};

byte closed_eyes_down[8] = {
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void function_eyes_closed()
{
  // top left
  lcd.setCursor(2,0);
  lcd.write(byte(0));
  lcd.setCursor(3,0);
  lcd.write(byte(0));
  lcd.setCursor(4,0);
  lcd.write(byte(0));
  lcd.setCursor(5,0);
  lcd.write(byte(0));
  
  // top right
  lcd.setCursor(10,0);
  lcd.write(byte(0));
  lcd.setCursor(11,0);
  lcd.write(byte(0));
  lcd.setCursor(12,0);
  lcd.write(byte(0));
  lcd.setCursor(13,0);
  lcd.write(byte(0));
  
  //down left
  lcd.setCursor(2,1);
  lcd.write(byte(1));
  lcd.setCursor(3,1);
  lcd.write(byte(1));
  lcd.setCursor(4,1);
  lcd.write(byte(1));
  lcd.setCursor(5,1);
  lcd.write(byte(1));
  
  //down right
  lcd.setCursor(10,1);
  lcd.write(byte(1));
  lcd.setCursor(11,1);
  lcd.write(byte(1));
  lcd.setCursor(12,1);
  lcd.write(byte(1));
  lcd.setCursor(13,1);
  lcd.write(byte(1));
 
}

byte open_eyes_top_center[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte open_eyes_top_left[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00011,
  0b00111,
  0b01111,
  0b11111
};

byte open_eyes_top_right[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11000,
  0b11100,
  0b11110,
  0b11111
};

byte open_eyes_down_center[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000
};

byte open_eyes_down_left[8] = {
  0b11111,
  0b01111,
  0b00111,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte open_eyes_down_right[8] = {
  0b11111,
  0b11110,
  0b11100,
  0b11000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};


void function_eyes_open()
{
  // top left
  lcd.setCursor(2,0);
  lcd.write(byte(4));
  
  lcd.setCursor(3,0);
  lcd.write(byte(2));
  lcd.setCursor(4,0);
  lcd.write(byte(2));
  
  lcd.setCursor(5,0);
  lcd.write(byte(6));
  
  // top right
  lcd.setCursor(10,0);
  lcd.write(byte(4));
  
  lcd.setCursor(11,0);
  lcd.write(byte(2));
  lcd.setCursor(12,0);
  lcd.write(byte(2));
  
  lcd.setCursor(13,0);
  lcd.write(byte(6));
  
  //down left
  lcd.setCursor(2,1);
  lcd.write(byte(5));
  
  lcd.setCursor(3,1);
  lcd.write(byte(3));
  lcd.setCursor(4,1);
  lcd.write(byte(3));
  
  lcd.setCursor(5,1);
  lcd.write(byte(7));
  
  //down right
  lcd.setCursor(10,1);
  lcd.write(byte(5));
  
  lcd.setCursor(11,1);
  lcd.write(byte(3));
  lcd.setCursor(12,1);
  lcd.write(byte(3));
  
  lcd.setCursor(13,1);
  lcd.write(byte(7));
}

void blinking()
{
  int delay_blink = random(4000,7500); // tempo com os olhos abertos varia
    
  function_eyes_open();
  delay(delay_blink);
  function_eyes_closed();
  delay(400);  
}

//------------------------------------------------------

void setup()
{
  lcd.begin(16, 2);
  lcd.createChar(0, closed_eyes_top);
  lcd.createChar(1, closed_eyes_down);
  lcd.createChar(2, open_eyes_top_center);
  lcd.createChar(3, open_eyes_down_center);
  lcd.createChar(4, open_eyes_top_left);
  lcd.createChar(5, open_eyes_down_left);
  lcd.createChar(6, open_eyes_top_right);
  lcd.createChar(7, open_eyes_down_right);
  lcd.clear();
  
  randomSeed(analogRead(A0)); // random seed
}

void loop()
{
  blinking();
}
