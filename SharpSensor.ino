int Sharp1 = 1;
int Sharp2 = 2;
int Sharp3 = 3; 

int Reading1;
int Reading2;
int Reading3;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  //stripe1();
  //forward(100,100,100);
  Reading1 = analogRead(Sharp1);
  Reading2 = analogRead(Sharp2);
  Reading3 = analogRead(Sharp3);
  
  Serial.println(Reading3);
 if (Reading3 > 220) {
  backward(100,100, 100);
  rotateRight1(30, 100, 100);
  forward(100, 100, 30); 
  }
  
  else if (Reading1 < 300 && Reading1 > 285 && Reading2 < 370)  // if you will change the other sensors adjust those numbers
  {
    forward(100,100, 100);  // try this for 100 maybe just test the others first
  } else {
    if (Reading1 > 285){     // change the sensors numbers to 300 or 200
      rotateRight1(30, 100, 30);
  
 }else if (Reading1 < 260){   // change the sensors numbers to 285 or 175
    forward(100, 100, 30);
    rotateLeft1(70, 10, 10);
    //forward(100,100,1000);
   
 /*}else if (Reading1 > 550){   // change this number to 500 maybe
  
   rotateRight1(30, 100, 10);
   forward(100,100, 10);
  */ 
 }else if (Reading2 > 350){
   
   rotateLeft1(80, 10, 10);

 }
 else { 
  forward(110,110, 100);
  
 }

  }
}
