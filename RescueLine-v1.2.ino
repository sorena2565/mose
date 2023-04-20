
//========================================================================---------------------------------------====================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-__-_-_-_-_-_-|                                       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|......................................................................|D E F I N E S  A N D  V A R I A B L E S|...................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--__-_-_-|                                       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//========================================================================---------------------------------------====================================================================

#include <Wire.h>
#include <VL53L0X.h>
#include <EEPROM.h>
#include <Wire.h>
#include <Servo.h>
//dynamixel
#include <SoftwareSerial.h>
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

  //sharp
    #define sharppin A4
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

  // int high = 255; 
  // int low = 247;  
  int high = 255;
  int low = 247;
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


void setup(){
  
  //servo //13 12 11 10
    servogr.attach(12);//baz 0 baste
    servogl.attach(10);//baz180

    servomr.attach(11);//bala 58 paiin 115
    servoml.attach(13);//bala 80 paiin 0
    servo("baz");
   
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
ax12_write2(2,730,30);
delay(1000);
}


void loop() {

bardasht("left");




}
  


//================================================================================-----------------===================================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|                 |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|..............................................................................|F U N C T I O N S|.................................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|                 |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//================================================================================-----------------===================================================================================
void bardasht(String m){
  if(m == "right"){
  servo("baste");
  delay(1000);
  dyna("up");
  delay(1000);
  servo("gr");
  delay(1000);
  dyna("down");
  }
  if(m == "left"){
  servo("baste");
  delay(1000);
  dyna("up");
  delay(1000);
  servo("gl");
  delay(1000);
  dyna("down");
  }
}
void shokhm(){
  if (sharp() < ballrange){

    bardasht("right");

  }
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
        Serial.println("aafsasjlk");
        turn_with_laser("left");

      }
      if (turn == true){
        turn_with_laser("right");
        motor("forward",forward,forward);
        delay(300);
        Serial.println("aafsasjlk");
        turn_with_laser("right");


      }
      turn=!turn ;
    }
  }   
 void dyna(String m){
  if(m == "up"){

    ax12_write2(2,70,30);
  }
  if(m == "down"){

    ax12_write2(2,730,30);
  }
  if(m == "midle"){
    ax12_write2(2,300,30);
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
    khat();
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
  else if(aa21 == onn){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("right",255,255);
      Serial.println("tond right");
    }
  }
  else if(aa20 == onn){
    ir();
    while(!(aa1 == onn)){
      ir();
      motor("left",255,255);
      Serial.println("tond left");
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
      servogr.write(29);
      servogl.write(151);
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
    if(m == "md"){
      servomr.write(0);
      servoml.write(180);
      delay(1000);
    }
    if(m == "mu"){
      servomr.write(90);
      servoml.write(90);
      delay(1000);
    }

}
int sharp(){
  
  return analogRead(sharppin);
}
