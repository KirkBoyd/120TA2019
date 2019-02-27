#include <Servo.h>;
#include <Wire.h>;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo myServo;
int servoport = 9;
int pos = 0;
void servoTest(int val){
    lcd.clear();
    lcd.print("pos");
    lcd.print(val, DEC);
    myServo.write(val);
    delay(50);
}
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(servoport, OUTPUT);
  myServo.attach(servoport);
  
}

void loop() {
  servoTest(90);
  for(int i=90; i<181;i++){
    servoTest(i);
    delay(1);
  }
  for(int i=180; i>-1;i--){
    servoTest(i);
    delay(1);
  }
  for(int i=0; i<91;i++){
    servoTest(i);
    delay(1);
  }
  delay(1000000000000);
//  int delta = 50;
//  for(pos=0; pos>181;pos++){
//    lcd.clear();
//    lcd.print("pos");
//    lcd.print(pos, DEC);
//    myServo.write(pos);
//    delay(delta);
//  }
//  for(pos=180; pos>0;pos--){
//    lcd.clear();
//    lcd.print("pos");
//    lcd.print(pos, DEC);
//    myServo.write(pos);
//    delay(delta);
//  }
}


