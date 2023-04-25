
//========================================================================---------------------------------------====================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-__-_-_-_-_-_-|                                       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|......................................................................|D E F I N E S  A N D  V A R I A B L E S|...................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--__-_-_-|                                       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//========================================================================---------------------------------------====================================================================

int sharp_pin = A4; // analog input pin for Sharp sensor
int sharp_val;
#include <Wire.h>
#include <VL53L0X.h>
#include <EEPROM.h>
#include <Wire.h>
#include <Servo.h>
#include <PixyI2C.h>
//dynamixel
#include <SoftwareSerial.h>
PixyI2C pixy;
//servo
  Servo servogr; 
  Servo servogl;

  Servo servomr; 
  Servo servoml; 
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
  //dynamixel

    //ax12_write2(2,70,30);dyna up
    //ax12_write2(2,760,30);dyna down

    #define AX_INST_PING                1
    #define AX_INST_READ_DATA           2
    #define AX_INST_WRITE_DATA          3
    #define AX_INST_REG_WRITE           4
    #define AX_INST_ACTION              5
    #define AX_INST_RESET               6
    #define AX_INST_SYNC_WRITE          131


  //...............cmps11...................
    #define _i2cAddress 0x60

    // CMPS11 compass registers
    #define BEARING_REGISTER  2 
    #define PITCH_REGISTER    4 
    #define ROLL_REGISTER     5
    
    #define ACCEL_X_REGISTER 12
    #define ACCEL_Y_REGISTER 14
    #define ACCEL_Z_REGISTER 16
    
    #define GYRO_X_REGISTER  18
    #define GYRO_Y_REGISTER  20
    #define GYRO_Z_REGISTER  22

    #define TEMP_REGISTER    24

    #define CONTROL_REGISTER  0

    #define ONE_BYTE 1
    #define TWO_BYTES 2

    //---------------------------------
    int balll = 0;
    int _bearing;
    int nReceived;
    byte _fine;
    byte _byteHigh;
    byte _byteLow;
    char _pitch;
    char _roll;

    float accelx = 0;
    float accely = 0;
    float accelz = 0;
    float _accelScale = 9.80665f * 2.0f/32768.0f; // setting the accel scale to 2G. Gravity = 9.80665 m/s^2

//---------------------------------
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
  //ir
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

//motors
  #define imr1 6 //input right motor
  #define imr2 3 //enable right motor
  #define iml1 7  //input left motor
  #define iml2 8
  #define eml 9  //input left motor
  #define emr 2

  //touch sensors
    #define tchfrp 61
    #define tchflp 62
    #define tchbrp 63
    #define tchblp 64

    #define ballon 11
    #define ballread 10

  //sharp
    #define sharppin A4
    #define ballrange 450
    #define noballrange 200

  //colors
    #define redr1 100
    #define redr2 200
    #define redl1 100
    #define redl2 200

    #define greenr1 550
    #define greenr2 610
    #define greenl1 480
    #define greenl2 540

    #define noghr1 500
    #define noghr2 600
    #define noghl1 500
    #define noghl2 600

  //servo motors
    #define servo1p 12   //servo paiin giriper rast
    #define servo2p 21   //servo paiin giriper chap
    #define servomrp 34   //servo makhzan rast
    #define servomlp 43   //servo makhzan left

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
  bool faze = false;

  // int high = 255; 
  // int low = 247;  
  int high = 255;
  int low = 235;
  int forward = 220;
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
 void ax12_write2(int id, int data,char ad_reg);
 void dyna(String m);
 void bardasht(String m);
 void servo(String m);
 void ball();
 void irtest();
 int pixyy();
 int rangg(String m);
 int pixyyy();
 int ballll();
 int ballkind();
 void setcolor(String m);


void setup(){
  /*
  servo("mrd");
  servo("mld");
  servo("baz");
  */
  pinMode(sharppin,INPUT);
  //servo //13 12 11 10
  /*
    servogr.attach(11);//baz 0 baste
    servogl.attach(10);//baz180

    servomr.attach(12);//bala 5 paiin 90
    servoml.attach(13);//bala 80 paiin 0
    
*/
  //cmps11
   Wire.begin();
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
  Serial1.begin(9600);
  Serial.begin(9600);
  //pixy
  pixy.init();

dyna("up");
}


void loop() {

Line();

}
//================================================================================-----------------===================================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|                 |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|..............................................................................|F U N C T I O N S|.................................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|                 |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//================================================================================-----------------===================================================================================
void bardasht(String m){
  if(m == "right"){

  delay(1000);
  dyna("up");
  delay(1000);
  if(sharp() < 500 && sharp() > 200){
    balll++;
  }
  servo("gr");
  delay(1000);
  dyna("down");
  servo("baz");
  delay(1000);
  }
  if(m == "left"){

  delay(1000);
  dyna("up");
  if(sharp() < 500 && sharp() > 200){
    balll++;
  }
  delay(1000);
  servo("gl");
  delay(1000);
  dyna("down");
  servo("baz");
  delay(1000);
  }
}
void shokhm(){
  if(laser("front") > 200){
    ball();
    motor("forward",forward,forward);
    }
    
  Serial.println(sharp());
  ball();
  if(balll > 2){
    rang = false;
    while(rang == false){
    rangg("green");
    if(tch("fr") == 1){
      digitalWrite(4,HIGH);
      servo("mlu");
      delay(1000);
    }  
    rangg("red");
    if(tch("fr") && tch("fl") == 1){
      digitalWrite(4,HIGH);
      servo("mru");
      delay(1000);
      rang = true;
      }
    }
  }
  if((ldr("right") < 500) || (ldr("left") < 450)){
    motor("left",255,255);
    delay(1000);
  }
  
  else if (laser("front") < 200){
    ball();
    Serial.println(sharp());
    motor("forward",0,0);
      if (turn == false){
        /*
        turn_with_laser("left");
        motor("forward",forward,forward); 
        delay(300);
        Serial.println("aafsasjlk");
        turn_with_laser("left");
        ball();
        delay(1000);
        */
        ball();
        motor("left",255,255);
        delay(1000);
      }
      if (turn == true){
        Serial.println(sharp());
        ball();
        /*
        turn_with_laser("right");
        motor("forward",forward,forward);
        delay(300);
        Serial.println("aafsasjlk");
        turn_with_laser("right");
        ball();
        delay(1000);
        */
        motor("right",255,255);
        delay(1000);
      }
      turn=!turn ;
      ball();
    }
    ball();
  } 
void setcolor(String m){
  if(m == "green"){
    greenr1 == ldr("right") - 30;
    greenr2 == ldr("right") + 30;

    greenl1 == ldr("left") - 30;
    greenl2 == ldr("left") + 30;
  }
  if(m == "nogh"){
    noghr1 == ldr("right") - 30;
    noghr2 == ldr("right") + 30;

    noghl1 == ldr("left") - 30;
    noghl2 == ldr("left") + 30;
  }
  if(m == "red"){
    redr1 == ldr("right") - 30;
    redr2 == ldr("right") + 30;

    redl1 == ldr("left") - 30;
    redl2 == ldr("left") + 30;
  }
}  
int rangg(String m){//.................................................
  if (m == "green"){
    while(!(tch("fr") && tch("fl") == 1)){

      if(!(pixyy() == "green")){
        
        if (rangg("line") == "right"){

          motor("right",60,60);
        }
        else if (rangg("line") == "left"){

          motor("left",60,60);
        }
      }
      if(pixyy() == "green"){

        motor("forward",222,222);  
        }      
      }
    }
  if (m == "red"){
    while(!(tch("fr") && tch("fl") == 1)){

      if(!(pixyy() == "red")){

        if (rangg("line") == "right"){

          motor("right",60,60);
        }
        else if (rangg("line") == "left"){

          motor("left",60,60);
        }
      }
      if(pixyy() == "red"){

      motor("forward",222,222);  
      }      
    }
  }   
  if(m == "line"){
    Serial.println(pixyyy());
    if(pixyyy() < 170 ){

      return "right";
    }  
    if(pixyyy() > 170 ){

      return "left";

    } 
  }
}    
 void dyna(String m){
  if(m == "up"){

    ax12_write2(2,70,30);
    delay(800);

  }
  if(m == "down"){

    ax12_write2(2,730,30);
    delay(800);

  }
  if(m == "midle"){
    ax12_write2(2,515,30);
 
  }
}
void Line(){
    /*
  if(((aa7 == onn || aa8 == onn || aa9 == onn ) && (aa11 == onn || aa12 == onn || aa13 == onn ) && (aa2 == onn || aa24 == onn))||(aa1 == onn && aa3 == onn && aa9 == onn && aa11 == onn && aa12 == onn)|| (aa1 == onn && aa17 == onn && aa9 == onn && aa11 == onn && aa8 == onn)||(aa6 == onn && aa15 == onn && aa24 == onn && aa1 == onn)||(aa5 == onn && aa14 == onn && aa2 == onn && aa24 == onn && aa1 == onn) ||(aa5 == onn && aa15 == onn && aa2 == onn && aa24 == onn && aa1 == onn) ){
    
    while(rang == true){
      ir();
      motor("back",forward,forward);
      delay(70);
      motor("forward",0,0); 
      delay(500);
      rang = false;
    }
    
    while(rang == false){
      delay(100);
      Serial.println(ldr("right"));

      if (greenr1 < ldr("right") && ldr("right") < greenr2){
        motor("right",200,250);
        delay(1000);
        rang = true;
      }
      
      else if(greenl1 < ldr("left") && ldr("left") < greenl2){
        motor("left",250,200);
        delay(1000);
        rang = true;
      }
      
      else{
        motor("forward",forward,forward);
        delay(300);
        rang = true;
      }
    }
    rang = false;
  } 
  */
   ir();
   digitalWrite(4,LOW);

  if(((ldr("right") < 530) && (ldr("right") > 430)) || ((ldr("left") < 480) && (ldr("left") > 380))){
    delay(100);
    if(aa1 == onn || aa18 == onn || aa23 == onn){
      faze = false;
    }
    else{
      faze = true;
    }
    
  }
  if (aa1 == onn){
      rang = true;
      motor("forward",forward,forward);
      Serial.println("forward");
      /*
      if(aa9 == onn){
        motor("left",high,low);
      }
      if(aa11 == onn){
        motor("right",low,high);
      }
      */

    }

  else if (aa12 == onn || aa16 == onn || aa21 == onn){
    motor("right",low,high);
    Serial.println("bish right");
    
  }
  else if (aa8 == onn || aa4 == onn || aa20 == onn){
    motor("left",high,low);
    Serial.println("bish left");
    
  }
  


  }
void khat(){
    ir();
    /*
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
    */
  if(aa21 == onn && aa10 == offf){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("right",low,high);
      Serial.println("return tond right");
      
    }
    delay(300);
  }
  else if(aa20 == onn && aa10 == offf){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("left",low,high);
      Serial.println("return tond left");
     
      
    }
    delay(300);
  }
  else if (aa18 == onn && aa1 == onn){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("left",high,low);
      Serial.println("l bala left");
      
    }
  }
  else if (aa23 == onn && aa1 == onn){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("right",low,high);
      Serial.println("l bala right");
      
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
void mane(String m){

  if(m == "line"){
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
      Line();
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
      Line();
    }
  }

  if (m == "takh"){
    while(laser("front") > 150){
      
      motor("forward",255,255);

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

      //delay
      motor("left",255,255);
      delay(1200);
      motor("forward",255,255);
      delay(500);
      motor("right",255,255);
      delay(1200);
      
    }
  }
}

  

int motor(String mode, int speadr, int speadl) {
  if (mode == "forward") {
    digitalWrite(imr1, HIGH);
    digitalWrite(imr2, LOW);
    analogWrite(emr, speadr);
    digitalWrite(iml1, LOW);
    digitalWrite(iml2, HIGH);
    analogWrite(eml, speadl);
  }
  if (mode == "back") {
    digitalWrite(imr1, LOW);
    digitalWrite(imr2, HIGH);
    analogWrite(emr, speadr);
    digitalWrite(iml1, HIGH);
    digitalWrite(iml2, LOW);
    analogWrite(eml, speadl);
  }
  if (mode == "right") {
    digitalWrite(imr1, LOW);
    digitalWrite(imr2, HIGH);
    analogWrite(emr, speadr);
    digitalWrite(iml1, LOW);
    digitalWrite(iml2, HIGH);
    analogWrite(eml, speadl);
  }
  if (mode == "left") {
    digitalWrite(imr1, HIGH);
    digitalWrite(imr2, LOW);
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
int ballkind(){
  digitalWrite(ballon,HIGH);
  return digitalRead(ballread);
}
int ballll(){
  if(ballkind() == 1){
    return "zende";
  }
  else{
    return "morde";
  }
}
//dynamixel
void ax12_write2(int id, int data,char ad_reg)
{
    int checksum = ~((id + 5 + AX_INST_WRITE_DATA + ad_reg + (data & 0xFF) + ((data & 0xFF00) >> 8)) % 256);
    Serial1.write(0xFF);
    Serial1.write(0xFF);
    Serial1.write(id);
    Serial1.write(5);
    Serial1.write(AX_INST_WRITE_DATA);
    Serial1.write(ad_reg);
    Serial1.write(data & 0xFF);
    Serial1.write((data & 0xFF00) >> 8);
    Serial1.write(checksum);
}
int getBearing()
{
  // begin communication with CMPS11
  Wire.beginTransmission(_i2cAddress);

  // Tell register you want some data
  Wire.write(BEARING_REGISTER);

  // End transmission
  int nackCatcher =
Wire.endTransmission();

  // Return if we have a connection problem  
  if(nackCatcher != 0){return 0;}
  
  // Request 2 bytes from CMPS11
  nReceived = Wire.requestFrom(_i2cAddress , TWO_BYTES);

  // Something has gone wrong
  if (nReceived != TWO_BYTES) return 0;
  
  // Read the values
  _byteHigh = Wire.read(); 
  _byteLow = Wire.read();

  // Calculate full bearing
  _bearing = ((_byteHigh<<8) + _byteLow) / 10;
  
  return _bearing;
}

signed char getPitch()
{
  // Begin communication with CMPS11
  Wire.beginTransmission(_i2cAddress);

  // Tell register you want some data
  Wire.write(PITCH_REGISTER);

  // End transmission
  int nackCatcher = Wire.endTransmission();

  // Return if we have a connection problem 
  if(nackCatcher != 0){return 0;}

  // Request 1 byte from CMPS11
  nReceived = Wire.requestFrom(_i2cAddress , ONE_BYTE);

  // Something has gone wrong
  if (nReceived != ONE_BYTE) return 0;
  
  // Read the values
  _pitch = Wire.read();

  return _pitch;
}

signed char getRoll()
{
  // Begin communication with CMPS11
  Wire.beginTransmission(_i2cAddress);

  // Tell register you want some data
  Wire.write(ROLL_REGISTER);

  // End transmission
  int nackCatcher = Wire.endTransmission();

  // Return if we have a connection problem 
  if(nackCatcher != 0){return 0;}

  // Request 1 byte from CMPS11
  nReceived = Wire.requestFrom(_i2cAddress , ONE_BYTE);

  // Something has gone wrong
  if (nReceived != ONE_BYTE) return 0;
  
  // Read the values
  _roll = Wire.read();

  return _roll;
}

int16_t getAcceleroX()
{
  // Begin communication with CMPS11
  Wire.beginTransmission(_i2cAddress);

  // Tell register you want some data
  Wire.write(ACCEL_X_REGISTER);

  // End the transmission
  int nackCatcher = Wire.endTransmission();

  // Return if we have a connection problem 
  if(nackCatcher != 0){return 0;}
  
  // Request 2 bytes from CMPS11
  nReceived = Wire.requestFrom(_i2cAddress , TWO_BYTES);

  // Something has gone wrong
  if (nReceived != TWO_BYTES) return 0;

  // Read the values
  _byteHigh = Wire.read(); 
  _byteLow = Wire.read();

  // Calculate Accelerometer
  return (((int16_t)_byteHigh <<8) + (int16_t)_byteLow);
}

int16_t getAcceleroY()
{
  // Begin communication with CMPS11
  Wire.beginTransmission(_i2cAddress);

  // Tell register you want some data
  Wire.write(ACCEL_Y_REGISTER);

  // End the transmission
  int nackCatcher = Wire.endTransmission();

  // Return if we have a connection problem 
  if(nackCatcher != 0){return 0;}
  
  // Request 2 bytes from CMPS11
  nReceived = Wire.requestFrom(_i2cAddress , TWO_BYTES);

  // Something has gone wrong
  if (nReceived != TWO_BYTES) return 0;

  // Read the values
  _byteHigh = Wire.read(); 
  _byteLow = Wire.read();

  // Calculate Accelerometer
  return (((int16_t)_byteHigh <<8) + (int16_t)_byteLow);
}

int16_t getAcceleroZ()
{
  // Begin communication with CMPS11
  Wire.beginTransmission(_i2cAddress);

  // Tell register you want some data
  Wire.write(ACCEL_Z_REGISTER);

  // End the transmission
  int nackCatcher = Wire.endTransmission();

  // Return if we have a connection problem 
  if(nackCatcher != 0){return 0;}
  
  // Request 2 bytes from CMPS11
  nReceived = Wire.requestFrom(_i2cAddress , TWO_BYTES);

  // Something has gone wrong
  if (nReceived != TWO_BYTES) return 0;

  // Read the values
  _byteHigh = Wire.read(); 
  _byteLow = Wire.read();

  // Calculate Accelerometer
  return (((int16_t)_byteHigh <<8) + (int16_t)_byteLow);
}
void servo(String m){
  //greeper 
    if(m == "baste"){
      servogr.write(30);
      servogl.write(150);
      delay(800);
    }
    if(m == "baz"){
      servogr.write(0);
      servogl.write(180);
      delay(800);
    }
    if(m == "gr"){
      servogr.write(0);
      servogl.write(138);
      delay(800);
      servogl.write(180);
    }
    if(m == "gl"){
      servogr.write(42);
      servogl.write(180);
      delay(800);
      servogr.write(0);
    }
  //makhzan
    if(m == "mrd"){
      servomr.write(90);
      delay(1000);
    }
    if(m == "mru"){
      servomr.write(10);
      delay(1000);
    }
    if(m == "mld"){
      servoml.write(90);
      delay(1000);
    }
    if(m == "mlu"){
      servoml.write(10);
      delay(1000);
    }

}
void ball(){
  if (sharp() < ballrange){

    digitalWrite(imr1, LOW);
    digitalWrite(imr2, LOW);
    analogWrite(emr, 200);
    digitalWrite(iml1, LOW);
    digitalWrite(iml2, LOW);
    analogWrite(eml, 200);
    servo("baste");
    if(ballll() == "zende"){
      bardasht("left");
    }
    else{
      bardasht("right");
    }
  }
}
void irtest(){
  ir();
Serial.print(aa1);
Serial.print(aa2);
Serial.print(aa3);
Serial.print(aa4);
Serial.print(aa5);
Serial.print(aa6);
Serial.print(aa7);
Serial.print(aa8);
Serial.print(aa9);
Serial.print(aa10);
Serial.print(aa11);
Serial.print(aa12);
Serial.print(aa13);
Serial.print(aa14);
Serial.print(aa15);
Serial.print(aa16);
Serial.print(aa17);
Serial.print(aa18);
Serial.print(aa19);
Serial.print(aa20);
Serial.print(aa21);
Serial.print(aa22);
Serial.print(aa23);
Serial.println(aa24);
}
int pixyy(){
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  blocks = pixy.getBlocks();
  
if (blocks)
  {
    i++;
    
    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i%50==0)
    {

      for (j=0; j<blocks; j++)
      {
        Serial.println(pixy.blocks[j].signature);

        if (pixy.blocks[j].signature == 1){
          Serial.println("red");
          return "red";
        }
        if (pixy.blocks[j].signature == 2){
          Serial.println("green");
          return "green";
        }
        if (pixy.blocks[j].signature == 3){
          Serial.println("blue");
          return "blue";
        }
      }
    }
  }  
}  
int pixyyy(){
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  blocks = pixy.getBlocks();
  
if (blocks)
  {
    i++;
    
    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i%50==0)
    {

      for (j=0; j<blocks; j++)
      {

        if (pixy.blocks[j].signature == 1){
          Serial.println("red");
          return pixy.blocks[j].x;
        }
        if (pixy.blocks[j].signature == 2){
          Serial.println("green");
          return pixy.blocks[j].x;
        }
        if (pixy.blocks[j].signature == 3){
          Serial.println("blue");
          return pixy.blocks[j].x;
        }
      }
    }
  }  
}  
int sharp(){
  distancej = analogRead(sharppin);
  return distancej;
}
