 // Connect a start switch/touch sensor to digital port 12
// Use analog port 1 for Sharp sensor
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address and config
// Global variables
int Sharp1 = 3; //use analog port 3 for Sharp sensor
int start_sw = 12; //digital port ID, start switch
int interval = 250; //interval between sensor readings
void start_press(int sw){
  //sw represents the digital port number that’s connected to the switch
  //function waits for switch to be pressed and released
  while(digitalRead(sw) == HIGH){} //exit when switch pressed
  while(digitalRead(sw) == LOW) {} // continue when switch released
}
void setup(){
  // initialize the display
  lcd.init();
  lcd.backlight();
  //clear the LCD and prompt the user
  lcd.clear();
  lcd.print("Hit Start Button");
  start_press(start_sw);
  pinMode(Sharp1, INPUT);
}
void loop(){
  int Reading;
  Reading = analogRead(Sharp1);
  //clear the LCD and print the sensor reading
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(Reading,DEC);
  delay(interval);
}
