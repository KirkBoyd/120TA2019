int directionL = 4;
int directionR =7;

int speedL= 5;
int speedR =6;

int stripe = 6;
int touchSensor= 11;

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
  
}

void loop() {
  TouchSensor();
 //forward(115,120,100);

}
