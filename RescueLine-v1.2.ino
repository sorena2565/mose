
//========================================================================---------------------------------------====================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-__-_-_-_-_-_-|                                       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|......................................................................|D E F I N E S  A N D  V A R I A B L E S|...................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--__-_-_-|                                       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//========================================================================---------------------------------------====================================================================

#include <Wire.h>
#include <VL53L0X.h>
#include <EEPROM.h>
//laser
  VL53L0X sensor; 
  VL53L0X sensor2;
  VL53L0X sensor3;
  VL53L0X sensor4;

  const int xshutPin = 44;
  const int xshutPin2 = 46;
  const int xshutPin3 = 47;
  const int xshutPin4 = 49;

#define HIGH_ACCURACY

  //servo timing
    #define servobazobaste 800
    #define servobazobala 1000
    #define makhzanbala 321
  

  int R_Speed=20;
  int robotv = 1 ; //switch 
    //IR sensors
  #define a1 39
  #define a2 24
  #define a3 23
  #define a4 22
  #define a5 69
  #define a6 68
  #define a7 67
  #define a8 31
  #define a9 30
  #define a10 14
  #define a11 29
  #define a12 28
  #define a13 27
  #define a14 41
  #define a15 40
  #define a16 37
  #define a17 36
  #define a18 26
  #define a19 25
  #define a20 32
  #define a21 33
  #define a22 35
  #define a23 34
  #define a24 15  
  //ldr
  #define ldrrp A6
  #define ldrlp A5
  #define tranr 65
  #define tranl 66
  //colores update status
  bool green = false;
  bool red = false;
  bool nogh = false;
  
  bool rang = false;//rang chahar rah
  bool aa1=0;
  bool aa2=0;
  bool aa3=0;
  bool aa4=0;
  bool aa5=0;
  bool aa6=0;
  bool aa7=0;
  bool aa8=0;
  bool aa9=0;
  bool aa10=0;
  bool aa11=0;
  bool aa12=0;  
  bool aa13=0;
  bool aa14=0;
  bool aa15=0;
  bool aa16=0;
  bool aa17=0;
  bool aa18=0;
  bool aa19=0;
  bool aa20=0;
  bool aa21=0;
  bool aa22=0;
  bool aa23=0;
  bool aa24=0;  

  #define onn 1
  #define offf 0

  #define greenr 100
  #define greenl 300
  #define returntime 1000 //how long does it take to return
  #define turnright 1000
  #define turnleft 1000




#define imr1 6 //input right motor
#define imr2 3 //enable right motor
#define iml1 7  //input left motor
#define iml2 8
#define eml 9  //input left motor
#define emr 2

// ostad milad koskhol soltan btc
  //touch sensors
    #define tchfrp 61
    #define tchflp 62
    #define tchbrp 63
    #define tchblp 64

  //sharp
    #define sharpPin A3
    #define ballrange 100
    #define noballrange 200

  //colors
    #define redr1 100
    #define redr2 200
    #define redl1 100
    #define redl2 200

    #define greenr1 550
    #define greenr2 700
    #define greenl1 550
    #define greenl2 700

    #define noghr1 500
    #define noghr2 600
    #define noghl1 500
    #define noghl2 600

  //servo motors
    #define servo1p 12   //servo paiin giriper rast
    #define servo2p 21   //servo paiin giriper chap
    #define servo3p 32   //servo giriper bala
    #define servomrp 34   //servo paiin makhzan rast
    #define servomlp 43   //servo paiin makhzan left

  //servos value
    //servo gripper paiin rast
      #define servo1baste 100
      #define servo1baz 200
      #define servo1rast 321
      #define servo1chap 232
    //servo gripper paiin chap
      #define servo2baste 100
      #define servo2baz 200
      #define servo2rast 321
      #define servo2chap 232
    //servo gropper bala
      #define servo3bala 21
      #define servo3paiin 21

      //----------------------------------------------------------------------------- V A R I A B L E S-------------------------------------------------------------------------------------
  //var
  int speedr = 0;
  int speedl = 0;

  unsigned long durationl;
  unsigned long durationr;
  unsigned long durationb;
  unsigned long durationj;
  int distanceb=0;
  int distancer=0;
  int distancel=0;
  int distancej=0;

  long duration;

  bool turn = true;

  // int high = 255; 
  // int low = 247;  
  int high = 220;
  int low = 210;
  int forward = 200;
 //11  12  1  7  9  19  18 
 int motor(String mode, int speadr, int speadl) ;
 int getBearing();
 signed char getPitch();
 signed char getRoll();
 int16_t getAcceleroX();
 int16_t getAcceleroY();
 int16_t getAcceleroZ();
 int cmps_cal(int a  , String j );
 int cmps();
 int calculateDistance();
 int laser(String m);
 void turn_with_laser(String mode);
 void turn_with_cmps(int a,String j);
 void shokhm();
 void Line();
 void ir();
 int sharp();
 void mane();
 int ldr(String m);
 void khat();
 int tch(String m);


void setup(){
//color setup  
  digitalWrite(tranr,HIGH);  
  digitalWrite(tranl,HIGH); 
  tch("br");
  if (tch("br") == 1){
    digitalWrite(4,HIGH);
    delay(1000);
    digitalWrite(4,LOW);

    while(green == false){
      if(tch("br") == 1){
        EEPROM.write(1, (analogRead(ldr("right"))/4));
      }
      if(tch("bl") == 1){
        EEPROM.write(2, (analogRead(ldr("left"))/4));
        green = true;
        }
      }  
    }

//laser

pinMode(xshutPin, OUTPUT);
  digitalWrite(xshutPin, LOW);

  delay(10);

  pinMode(xshutPin2, OUTPUT);
  digitalWrite(xshutPin2, LOW);

  delay(10);

  pinMode(xshutPin3, OUTPUT);
  digitalWrite(xshutPin3, LOW);

  Serial.begin(115200);
  Wire.begin();

  digitalWrite(xshutPin, HIGH);
  delay(10);
  sensor.init();
  sensor.setTimeout(200);
  sensor.setAddress((uint8_t)48);
  delay(10);

#if defined LONG_RANGE
  // lower the return signal rate limit (default is 0.25 MCPS)
  sensor.setSignalRateLimit(0.1);
  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif

#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  sensor.setMeasurementTimingBudget(2000);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  sensor.setMeasurementTimingBudget(20000);
#endif

  digitalWrite(xshutPin2, HIGH);
  delay(10);
  sensor2.init();
  sensor2.setTimeout(200);
  sensor2.setAddress((uint8_t)49);
  delay(10);

#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  sensor2.setMeasurementTimingBudget(2000);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  sensor2.setMeasurementTimingBudget(20000);
#endif
digitalWrite(xshutPin3, HIGH);
  delay(10);
  sensor3.init();
  sensor3.setTimeout(200);
  sensor3.setAddress((uint8_t)50);
  delay(10);

#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  sensor2.setMeasurementTimingBudget(2000);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  sensor2.setMeasurementTimingBudget(20000);
#endif

//laser...............
  pinMode(a1,INPUT);
  pinMode(a2,INPUT);
  pinMode(a3,INPUT);
  pinMode(a4,INPUT);
  pinMode(a5,INPUT);
  pinMode(a6,INPUT);
  pinMode(a7,INPUT);
  pinMode(a8,INPUT);
  pinMode(a9,INPUT);
  pinMode(a10,INPUT);
  pinMode(a11,INPUT);
  pinMode(a12,INPUT);
  pinMode(a13,INPUT);
  pinMode(a14,INPUT);
  pinMode(a15,INPUT);
  pinMode(a16,INPUT);
  pinMode(a17,INPUT);
  pinMode(a18,INPUT);
  pinMode(a19,INPUT);
  pinMode(a20,INPUT);
  pinMode(a21,INPUT);
  pinMode(a22,INPUT);
  pinMode(a23,INPUT);
  pinMode(a24,INPUT);

  pinMode(ldrrp,INPUT);
  pinMode(ldrlp,INPUT);

  pinMode(imr1, OUTPUT);  //IN2
  pinMode(imr2, OUTPUT);  //IN1
  pinMode(emr, OUTPUT);   //Enable Pin
  pinMode(iml1, OUTPUT);  //IN2
  pinMode(iml2, OUTPUT);  //IN1
  pinMode(eml, OUTPUT);   //Enable Pin

  pinMode(4,OUTPUT);
  //on/off LED
  Serial.begin(9600);

}
//==================================================================================-------==========================================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|................................................................................|L O O P|.........................................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//==================================================================================-------==========================================================================================
void loop() {

Line();
}
  


//================================================================================-----------------===================================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|                 |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|..............................................................................|F U N C T I O N S|.................................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|                 |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//================================================================================-----------------===================================================================================

void shokhm(){
   Serial.println(turn);
 
  if(laser("front") > 100){
      motor("forward",forward,forward);
      Serial.println(turn);
    }
  else if (laser("front") < 450){
    motor("forward",0,0);
      if (turn == false){
        turn_with_laser("left");
        motor("forward",forward,forward);
        delay(300);
        /*
        int u_laser = laser("front");
        while(((u_laser-100) - laser("front")) < 0){ 
          Serial.println("moradi jan nakhondam");
          delay(1);
        }
        */
        Serial.println("aafsasjlk");
        turn_with_laser("left");

      }
      if (turn == true){
        turn_with_laser("right");
        motor("forward",forward,forward);
         delay(300);
        /*
        int u_laser = laser("front");
        while(((u_laser-100) - laser("front")) < 0){ 
          Serial.println("moradi jan nakhondam");
          delay(1);
        }
        */
        Serial.println("aafsasjlk");
        turn_with_laser("right");


      }
      turn=!turn ;
    }
  }   
 
void Line(){
   ir();
   

  if ((aa6 == onn && aa14 == onn && aa2 == onn && aa24 == onn && aa1 == onn)||(aa6 == onn && aa15 == onn && aa24 == onn && aa1 == onn)||(aa5 == onn && aa14 == onn && aa2 == onn && aa24 == onn && aa1 == onn) ||(aa5 == onn && aa15 == onn && aa2 == onn && aa24 == onn && aa1 == onn) ){
    while(rang == true){
    ir();
    motor("back",forward,forward);
    delay(60);
    motor("forward",0,0); 
    delay(500);
    rang = false;
    }
    while(rang == false){
      delay(100);
      Serial.println(ldr("right"));
      if (700 < ldr("right") && ldr("right") < 800){

        motor("right",low,high);
        delay(800);
        rang = true;

      }
      
      else if(600 < ldr("left") && ldr("left") < 700){

        motor("left",low,high);
        delay(800);
        rang = true;

      }
      
      else{
        motor("forward",forward,forward);
        delay(500);
        rang = true;
      }
      
    }
    rang = false;
  } 
  /*
  if (aa6 == onn && aa1 == onn && aa2 == onn && aa14 == offf){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("right",low,high);
      Serial.println("3 rah right");
      khat();
    }
  }  

  if (aa14 == onn && aa1 == onn && aa2 == onn && aa6 == offf){  
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("left",high,low);
      Serial.println("3 rah left");
      khat();
    }

  }
*/
  
  
  

  /*
  else if ( aa10 == onn && aa6 == onn ){
    ir();
    digitalWrite(4,HIGH);
    while(!(aa1 == onn)){
      ir();
      motor("left",250,240);
    }
  }
  */
  else if (aa12 == onn || aa13 == onn || aa14 == onn){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("right",low,high);
      Serial.println("bish right");
      khat();
    }
  }
  else if (aa8 == onn || aa7 == onn || aa6 == onn){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("left",high,low);
      Serial.println("bish left");
      khat();
    }
  }

/*

  else if (aa11 == onn && aa13 == offf){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("right",50,255);
      Serial.println("enheraf right");
      khat();
    }
  }
  
  else if (aa9 == onn && aa7 == offf){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("left",255,50);
      Serial.println("enheraf left");
      khat();
      }
    }
    */
  else if (aa1 == onn ){
    rang = true;
    digitalWrite(4,LOW);
    motor("forward",forward,forward);
    
    //Serial.println("forward");
    
  }
  }
void khat(){
    ir();
    if (aa14 == onn && aa2 == offf && aa24 == offf){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("right",255,255);
      Serial.println("enheraf right");
    }
  }
  
  else if (aa6 == onn && aa2 == offf && aa24 == offf){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("left",255,255);
      Serial.println("enheraf left");
      }
    }
}
int laser(String m){
  if (m == "back"){
    distanceb = sensor4.readRangeSingleMillimeters();
    return distanceb;
  }
  if (m == "front"){
    distancej = sensor3.readRangeSingleMillimeters();
    return distancej;
  }
  if (m == "right"){
    distancer = sensor2.readRangeSingleMillimeters();
    return distancer;
  }
  if (m == "left"){
  distancel = sensor.readRangeSingleMillimeters();
  return distancel;
  }
  
  }
int ldr(String m){
  if(m == "right"){
    return analogRead(ldrrp);
  }
  if(m == "left"){
    return analogRead(ldrlp);
  }
}  
int tch(String m){
  if(m == "br"){
    return analogRead(tchbrp);
  }
  if(m == "bl"){
    return analogRead(tchblp);
  }
  if(m == "fr"){
    return analogRead(tchfrp);
  }
  if(m == "fl"){
    return analogRead(tchflp);
  }
}
void turn_with_laser(String mode){


  if (mode == "right"){
    
    laser("left");
    if (distancel > 90){
      while (distancel > 90){
        Serial.println(distancel);
        motor("right",255,255);
        laser("left");
        }
      }
    else{
      laser("back");
      while (distanceb > 45){
        Serial.println(distanceb);
        motor("right",255,255);
        laser("back");
        }
      }  
    }  
  if (mode == "left"){
    laser("right");
    if (distancer > 90){
      while (distancer > 90){
        Serial.println(distancer);
        motor("left",255,255);
        laser("right");
        }
      }
    else{
      laser("back");
      while (distanceb > 45){
        Serial.println(distanceb);
        motor("left",255,255);
        laser("back");
      }
    }
  }
}    
void mane(){


  while(laser("front") > 150){
    
      motor("forward",255,255);
      Serial.println(distancej);
  }
    motor("forward",0,0);
    
  

 
  if(laser("right") > laser("left")){
    turn_with_laser("right");


    motor("forward",255,255);
    delay(700);
    motor("left",255,255);
    delay(1200);
    while(laser("left") > 160){
      motor("forward",255,255);
      delay(3);
      }
    delay(700); 
    ir();
    while(!(aa10 == onn)){ 
      ir();
    while(laser("left") > 160){
      motor("left",255,255);
      delay(300);
      }  
      motor("forward",255,255);
      
      delay(1);  
    }

  }

  if(laser("left") > laser("right")){
    turn_with_laser("left");


    motor("forward",255,255);
    delay(700);
    motor("right",255,255);
    delay(1200);
    while(laser("right") > 160){
      motor("forward",255,255);
      delay(3);
      }
    delay(700); 
    ir();
    while(!(aa10 == onn)){ 
      ir();
    while(laser("right") > 160){
      motor("right",255,255);
      delay(300);
      }  
      motor("forward",255,255);
      
      delay(1);  
    }

  }
  
  
}
int motor(String mode, int speadr, int speadl) {
  if (mode == "forward") {
    digitalWrite(imr1, LOW);
    digitalWrite(imr2, HIGH);
    analogWrite(emr, speadr);
    digitalWrite(iml1, LOW);
    digitalWrite(iml2, HIGH);
    analogWrite(eml, speadl);
  }
  if (mode == "back") {
    digitalWrite(imr1, HIGH);
    digitalWrite(imr2, LOW);
    analogWrite(emr, speadr);
    digitalWrite(iml1, HIGH);
    digitalWrite(iml2, LOW);
    analogWrite(eml, speadl);
  }
  if (mode == "right") {
    digitalWrite(imr1, HIGH);
    digitalWrite(imr2, LOW);
    analogWrite(emr, speadr);
    digitalWrite(iml1, LOW);
    digitalWrite(iml2, HIGH);
    analogWrite(eml, speadl);
  }
  if (mode == "left") {
    digitalWrite(imr1, LOW);
    digitalWrite(imr2, HIGH);
    analogWrite(emr, speadr);
    digitalWrite(iml1, HIGH);
    digitalWrite(iml2, LOW);
    analogWrite(eml, speadl);
  }
  };
void ir(){
aa1=digitalRead(a1);
aa2=digitalRead(a2);
aa3=digitalRead(a3);
aa4=digitalRead(a4);
aa5=digitalRead(a5);
aa6=digitalRead(a6);
aa7=digitalRead(a7);
aa8=digitalRead(a8);
aa9=digitalRead(a9);
aa10=digitalRead(a10);
aa11=digitalRead(a11);
aa12=digitalRead(a12);  
aa13=digitalRead(a13);
aa14=digitalRead(a14);
aa15=digitalRead(a15);
aa16=digitalRead(a16);
aa17=digitalRead(a17);
aa18=digitalRead(a18);
aa19=digitalRead(a19);
aa20=digitalRead(a20);
aa21=digitalRead(a21);
aa22=digitalRead(a22);
aa23=digitalRead(a23);
aa24=digitalRead(a24);
}    

