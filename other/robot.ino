
  #include <Servo.h>
  #include <Wire.h>
  #include "setup.h"
  
 int motor(String mode, int speadr, int speadl);
 int getBearing();
 signed char getPitch();
 signed char getRoll();
 int16_t getAcceleroX();
 int16_t getAcceleroY();
 int16_t getAcceleroZ();
 int cmps_cal(int a  , String j );
 void tch();
 int cmps();
 int calculateDistance();
 int laser(String m);
 void turn_with_laser(int mode);
 void turn_with_cmps(int a,String j);
 void shokhm();
 void Line();


void setup(){

  pinMode(trig, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo, INPUT); // Sets the echoPin as an Input

  pinMode(pinb  ,INPUT);//lasers
  pinMode(pinr,INPUT);
  pinMode(pinl,INPUT);

  pinMode(imr1, OUTPUT);  //IN2
  pinMode(imr2, OUTPUT);  //IN1
  pinMode(emr, OUTPUT);   //Enable Pin
  pinMode(iml1, OUTPUT);  //IN2
  pinMode(iml2, OUTPUT);  //IN1
  pinMode(eml, OUTPUT);   //Enable Pin
  Serial.begin(9600);

  Wire.begin();

  //Servos setup
  servomr.attach(servomrp);
  servoml.attach(servomlp);
  servo1.attach(servo1p);
  servo2.attach(servo2p);
  servo3.attach(servo3p);

  //touch sensors
  pinMode(tchFlp, INPUT);
  pinMode(tchFrp, INPUT);
  pinMode(tchBlp, INPUT);
  pinMode(tchBrp, INPUT);
  //ldr
  pinMode(ldrR, INPUT);
  pinMode(ldrL, INPUT);



/*
    if (j == "left"){
      status = 10;
      while(!( x + 5 > bearing > x - 5)){
        cmps();
        
      }
      status = 4;
    }
*/

}
//==================================================================================-------==========================================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|................................................................................|L O O P|.........................................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//==================================================================================-------==========================================================================================
void loop() {
if (faze)
  shokhm();
else if(!faze)
  Line();



}
  


//================================================================================-----------------===================================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|                 |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|..............................................................................|F U N C T I O N S|.................................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|                 |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//================================================================================-----------------===================================================================================
 
 void shokhm(){
   

  
if(laser("front") > 100){
    motor("forward",255,255);
   }
else if (laser("front") < 100){
    if (turn == false){
      motor("left",255,255);
      delay(1900);
      motor("forward",255,255);
      int u_laser = laser("front");
      while(((u_laser-100) - laser("front")) < 0){
        Serial.println("moradi jan nakhondam");
        delay(1);
      }
      motor("left",255,255);
      delay(1900);
      motor("back",255,255);
      while((digitalRead(tchBlp) && digitalRead(tchBrp))) delay(1); 
    }
    if (turn == true){
      motor("right",255,255);
      delay(1900);
      motor("forward",255,255);
      int u_laser = laser("front");
      while(((u_laser-100) - laser("front")) < 0){
        Serial.println("moradi jan nakhondam");
        delay(1);
      }
      motor("right",255,255);
      delay(1900);
      motor("back",255,255);
      while((digitalRead(tchBlp) && digitalRead(tchBrp))) delay(1); 

    }
    turn=!turn ;
   }
  }   
 
 void Line(){}
  int getBearing()
  {
    // begin communication with CMPS11
    Wire.beginTransmission(_i2cAddress);

    // Tell register you want some data
    Wire.write(BEARING_REGISTER);

    // End transmission
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
  int cmps_cal(int a  , String j ) {
  x = cmps();
if (j == "right"){
  for (int i = 0; i < a ; i++)
    if (x < 360)
      x++ ;

    
  if (x == 360)
      x == 0;
    
  }

if (j == "left"){
  for (int i = 0; i < a ; i++){

    if (x > 0){
      x-- ;

    }
    if (x == 0){
        x = 360;
    };

    }

}
return x;
}
  void tch(){
    tchBr=digitalRead(tchBrp);
    tchBl=digitalRead(tchBlp);
    tchFr=digitalRead(tchFrp); 
    tchFl=digitalRead(tchFlp);   
  }
  int cmps(){
    bearing = getBearing();

    pitch = getPitch();

    roll = getRoll();
    
    // Read the accelerator
    accelx = getAcceleroX() * _accelScale;
    accely = getAcceleroY() * _accelScale;
    accelz = getAcceleroZ() * _accelScale;

    return bearing;

    
  }
  int calculateDistance(){ 

    digitalWrite(trig, LOW); 
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trig, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
    distanceb= duration*0.034/2*10;
    return distanceb;
    }
  int laser(String m){
    delay(20);
    if (m == "back"){
      durationb = pulseIn(pinb, HIGH);
      distanceb=durationb/10;
      return distancej;
    }
    if (m == "front"){
      distancej = calculateDistance();
      Serial.println(distancej);
      return distancej;
    }
    if (m == "right"){
      durationr = pulseIn(pinr, HIGH);
      distancer=durationr/10;
      return distancer;
    }
    if (m == "left"){
    durationl = pulseIn(pinl, HIGH);
    distancel = durationl/10;
    return distancel;
    }
    
    }
/*
  void turn_with_laser(int mode){

    laser("front");
    if (distancej < 130){

      if (mode == "right"){

        laser("right");
        if (distancer < 130){
          while (distanceb > 130){
            Serial.println(distanceb);
            status = 6;
            laser();
            }
            tch();
            if(tchBr || tchBl == 0){
              while(!(tchBr && tchBl == 1)){
                status = 11;
                tch();
              }
            }
          }
        else{
          while (distancer > 130){
            Serial.println(distancer);
            status = 6;
            laser("right");
            }
          }
        }
      }
      else if (mode == "left"){

        laser("left");
        if (distancel < 130){
          while (distanceb > 130){
            Serial.println(distanceb);
            status = 9;
            laser();
            }
            tch();
            if(tchBr || tchBl == 0){
              while(!(tchBr && tchBl == 1)){
                status = 11;
                tch();
              }
              
            }
          }
        else{
        while (distancel > 130){
          Serial.println(distancel);
          status = 9;
          laser("left");
          }
        }  
    }  

    else if (distancer < 130){
      laser();
      while(distanceb > 85){
        status = 10;
        laser();
      };
    }

    else if (distancel < 130){
      laser();
      while(distanceb > 85){
        status = 7;
        laser();
      };
    }
    
      
    
  }
  */
  void turn_with_cmps(int a,String j){//...............................................................................................
    cmps_cal(a,j);

    if (j == "right"){
      int cmps = getBearing();
      cmps =  cmps  + 90;
      a=0;
      while(_bearing - cmps > -89){
        getBearing();
        Serial.println(bearing);
        motor("right",200,200);

      }
      motor("right",0,0);
      
    }
    if (j == "left"){
      while(!( x + 5 > bearing > x - 5)){
        cmps();
        
      }
      // status = 4;
    }


   }
  
  int motor(String mode, int speadr, int speadl) {
        if (mode == "forward") {
          digitalWrite(imr1, HIGH);
          digitalWrite(imr2, LOW);
          analogWrite(emr, speadr);
          digitalWrite(iml1, HIGH);
          digitalWrite(iml2, LOW);
          analogWrite(eml, speadl);
        }
        if (mode == "back") {
          digitalWrite(imr1, LOW);
          digitalWrite(imr2, HIGH);
          analogWrite(emr, speadr);
          digitalWrite(iml1, LOW);
          digitalWrite(iml2, HIGH);
          analogWrite(eml, speadl);
        }
        if (mode == "right") {
          digitalWrite(imr1, LOW);
          digitalWrite(imr2, HIGH);
          analogWrite(emr, speadr);
          digitalWrite(iml1, HIGH);
          digitalWrite(iml2, LOW);
          analogWrite(eml, speadl);
        }
        if (mode == "left") {
          digitalWrite(imr1, HIGH);
          digitalWrite(imr2, LOW);
          analogWrite(emr, speadr);
          digitalWrite(iml1, LOW);
          digitalWrite(iml2, HIGH);
          analogWrite(eml, speadl);
        }
      }

