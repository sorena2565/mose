//========================================================================---------------------------------------====================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-__-_-_-_-_-_-|                                       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|......................................................................|D E F I N E S  A N D  V A R I A B L E S|...................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--__-_-_-|                                       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//========================================================================---------------------------------------====================================================================
  //servo timing
    #define servobazobaste 800
    #define servobazobala 1000
    #define makhzanbala 321
  
//touch sensors
  #define tchfl 22
  #define tchfr 23
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
  #define ldr1p A1
  #define ldr2p A2
  #define greenl 100
  #define greenh 300
  #define returntime 1000 //how long does it take to return
  #define turnright 1000
  #define turnleft 1000



#define imr1 6 //input right motor
#define imr2 3 //enable right motor
#define iml1 7  //input left motor
#define iml2 8
#define eml 9  //input left motor
#define emr 2

// ostad milad
  //touch sensors
    #define tchFrp 22
    #define tchFlp 23
    #define tchBrp 22
    #define tchBlp 23
  //sharp
    #define sharpPin A3
    #define ballrange 100
    #define noballrange 200

  //ldr
    #define ldrR 68
    #define ldrL 59

  //colors
    #define red1 100
    #define red2 200
    #define green1 300
    #define green2 400
    #define nogh1 500
    #define nogh2 600
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
  //lasers pin
    #define pinr 10
    #define pinl 9
    #define pinb A0

  //cmps
    //Address of the CMPS11 compass on i2C
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





      //----------------------------------------------------------------------------- V A R I A B L E S-------------------------------------------------------------------------------------
  //var
  int speedr = 0;
  int speedl = 0;

  unsigned long durationl;
  unsigned long durationr;
  unsigned long durationb;
  int distanceb=0;
  int distancer=0;
  int distancel=0;
  int distancej=0;
  int x=0;
  //servos
  Servo servo1;//right servo in greeper
  Servo servo2;//left servo in greeper
  Servo servo3;//dynamixel :/ 
  Servo servomr;//right servo in makhzan
  Servo servoml;//left servo in makhzan

  long duration;
  int pos = 0; 

  int turndegree = 0;

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
  float _accelScale = 9.80665f * 2.0f/32768.0f; 

  const int trig = 12;
  const int echo = 13;

  int bearing ;

  signed char pitch ;

  signed char roll ;

  String forward = "";
  String back = "";
  String right = "";
  String left = "";

  //touch sensors
  bool tchFr = 0;
  bool tchFl = 0;

  bool tchBr = 0;
  bool tchBl = 0;

  int speadr = 250;
  int speadl = 250;

  // int status = 0;

  int ldrRr = 0;
  int ldrLl = 0;

  int a = 0 ;
  int b = 0 ;
  String j ="";
bool faze =true;
  bool takhlie = true;
  bool charkhesh = false;
  bool turn = true;



