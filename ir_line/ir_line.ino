//========================================================================---------------------------------------====================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-__-_-_-_-_-_-|                                       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|......................................................................|D E F I N E S  A N D  V A R I A B L E S|...................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--__-_-_-|                                       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//========================================================================---------------------------------------====================================================================
#include"Setup.h"


  //library 
//================================================================================-----------------===================================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|                 |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|..............................................................................|F U N C T I O N S|.................................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|                 |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//================================================================================-----------------===================================================================================
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
// ===============================================================================---------------====================================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|               |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|..............................................................................|S W I T C H E S|...................................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|               |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
// ===============================================================================---------------====================================================================================

void setup() {
//================================================================================---------==========================================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|         |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|..............................................................................|S E T U P|.........................................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|         |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//================================================================================---------==========================================================================================
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
/*
int mode = 8;
int aphase = 9;
int aenbl = 6;
int bphase = 5;
int benbl = 3;
*/
pinMode(imr1,OUTPUT);
pinMode(imr2,OUTPUT);
pinMode(iml1,OUTPUT);
pinMode(iml2,OUTPUT);
pinMode(emr,OUTPUT);
pinMode(eml,OUTPUT);

Serial.begin(9600);

}
void loop() {
//==================================================================================-------==========================================================================================
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//|................................................................................|L O O P|.........................................................................................|
//|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|       |-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|
//==================================================================================-------==========================================================================================
ir();

if (aa24 == onn && aa2 == onn && aa10 == onn){
  motor("forward",255,255);
  Serial.println("forward");
  ir();
}
else if (aa9 == onn){
  ir();
  while (!(aa24 == onn && aa2 == onn && aa10 == onn)){
    ir();
  motor("left",255,150);
    Serial.println("left 9");
  }
  motor("right",255,255);
  delay(10);
  motor("forward",255,255);
    delay(10);
}
else if (aa8 == onn){
  ir();
  while (!(aa24 == onn && aa2 == onn && aa10 == onn)){
    ir();
  motor("left",255,150);
    Serial.println("left 8");
  }
  motor("right",255,255);
  delay(10);
  motor("forward",255,255);
    delay(10);
}
else if (aa7 == onn){
  ir();
  while (!(aa24 == onn && aa2 == onn && aa10 == onn)){
    ir();
  motor("left",255,150);
    Serial.println("left 7");
  }
  motor("right",255,255);
  delay(10);
  motor("forward",255,255);
    delay(10);
}
else if (aa6 == onn){
  ir();
  while (!(aa24 == onn && aa2 == onn && aa10 == onn)){
    ir();
  motor("left",255,150);
    Serial.println("left 6");
  }
  motor("right",255,255);
  delay(10);
  motor("forward",255,255);
    delay(10);
}
else if (aa5 == onn){
  ir();
  while (!(aa24 == onn && aa2 == onn && aa10 == onn)){
    ir();
  motor("left",255,150);
    Serial.println("left 5");
  }
  motor("right",255,255);
  delay(10);
  motor("forward",255,255);
    delay(10);
}
else if (aa11 == onn){
  ir();
  while (!(aa24 == onn && aa2 == onn && aa10 == onn)){
    ir();
  motor("right",255,150);
    Serial.println("right 11");
  }
  motor("left",255,255);
  delay(10);
  motor("forward",255,255);
    delay(10);
}
else if (aa12 == onn){
  ir();
  while (!(aa24 == onn && aa2 == onn && aa10 == onn)){
    ir();
  motor("right",255,150);
    Serial.println("right 12");
  }
  motor("left",255,255);
  delay(10);
  motor("forward",255,255);
    delay(10);
}
else if (aa13 == onn){
  ir();
  while (!(aa24 == onn && aa2 == onn && aa10 == onn)){
    ir();
  motor("right",255,150);
    Serial.println("right 13");
  }
  motor("left",255,255);
  delay(10);
  motor("forward",255,255);
    delay(10);
}
else if (aa14 == onn){
  ir();
  while (!(aa24 == onn && aa2 == onn && aa10 == onn)){
    ir();
  motor("right",255,150);
    Serial.println("right 14");
  }
  motor("left",255,255);
  delay(10);
  motor("forward",255,255);
    delay(10);
}
else if (aa15 == onn){
  ir();
  while (!(aa24 == onn && aa2 == onn && aa10 == onn)){
    ir();
  motor("right",255,150);
    Serial.println("right 15");
  }
  motor("left",255,255);
  delay(10);
  motor("forward",255,255);
    delay(10);
}




  }
