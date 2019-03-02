int directionL = 4;  
int directionR =7;

int speedL= 5;
int speedR =6;

int stripe = 6;
int touchSensor= 11;

int Sharp1 = 1;
int Sharp2 = 2;
int Sharp3 = 3; 

int Reading1;
int Reading2;
int Reading3;

void setSpeed(int s){
  analogWrite(speedL,s);
  analogWrite(speedR, s);
}

void forward(int s, int s1, int msec){
  brakeOff();
  digitalWrite(directionL,HIGH);
   digitalWrite(directionR,HIGH);
   analogWrite(speedL, s);
   analogWrite(speedR, s1);
   delay(msec); 
}
void backward(int s, int s1, int msec){
  brakeOff();
  digitalWrite(directionL,LOW);
   digitalWrite(directionR,LOW);
   analogWrite(speedL, s);
   analogWrite(speedR, s1);
   delay(msec); 
}
void brakeOff(){
   digitalWrite(speedL,HIGH);
   digitalWrite(speedR,HIGH);
}
void rotateLeft(int s, int s1, int msec){
  brakeOff();
  digitalWrite(directionL,LOW);
   digitalWrite(directionR,HIGH);
   analogWrite(speedL, s);
   analogWrite(speedR, s1);
   delay(msec); 
}
void rotateRight(int s, int s1, int msec){
  brakeOff();
  digitalWrite(directionL,HIGH);
   digitalWrite(directionR,LOW);
   analogWrite(speedL, s);
   analogWrite(speedR, s1);
   delay(msec); 
}

void TouchSensor(){
  if(digitalRead(touchSensor) == LOW){
    backward(150,150,1000); 
    rotateLeft(100,100,200);
    rotateLeft(100,100,200);
  } else if (digitalRead(touchSensor)== HIGH){
    forward(200,200,100);
  }

  
}
void setup() {
  pinMode(directionL,OUTPUT);
  pinMode(directionR, OUTPUT);

  pinMode(speedL,OUTPUT);
  pinMode(speedR,OUTPUT);

   pinMode(touchSensor,INPUT);
   Serial.begin(9600);
}

void loop() {
  //TouchSensor();
 //forward(115,120,100);
 //stripe1();
  //forward(100,100,100);
  Reading1 = analogRead(Sharp1);
  Reading2 = analogRead(Sharp2);
  //Reading3 = analogRead(Sharp3);
  //delay(1000);
  //Serial.print("sharp1: ");
  //Serial.println(Reading1);
  delay(1000);
   Serial.print("sharp2: ");
   Serial.println(Reading2);
   
   /*if (Reading1 < 123){   // change the sensors numbers to 285 or 175
    forward(80, 80, 30);
    rotateLeft(70, 10, 10);
    forward(80,80,100);
    
   } else if (Reading1 > 524){
    rotateRight(10,80,10);
    forward(80,80,100);
   */
    //forward(80,80,100);
    if (Reading2 > 370){
    rotateRight(10,80,10);
    //forward(30,30,30);
    
   } else if (Reading2 < 200){
      rotateLeft(80,10,40);
      //forward(30,30,10);
   }
   else {
    forward(100,100,100);
   }
   
 /*if (Reading3 > 220) {
  backward(100,100, 100);
  rotateRight(30, 100, 100);
  forward(100, 100, 30); 
  }
  
  else if (Reading1 < 300 && Reading1 > 285 && Reading2 < 370)  // if you will change the other sensors adjust those numbers
  {
    forward(100,100, 100);  // try this for 100 maybe just test the others first
  } else {
    if (Reading1 > 285){     // change the sensors numbers to 300 or 200
      rotateRight(30, 100, 30);
  
 }else if (Reading1 < 260){   // change the sensors numbers to 285 or 175
    forward(100, 100, 30);
    rotateLeft(70, 10, 10);
    //forward(100,100,1000);
   
 /*}else if (Reading1 > 550){   // change this number to 500 maybe
  
   rotateRight1(30, 100, 10);
   forward(100,100, 10);
  */ 
 /*}else if (Reading2 > 350){
   
   rotateLeft(80, 10, 10);

 }
 else { 
  forward(110,110, 100);
  
 }

 /*/ }

