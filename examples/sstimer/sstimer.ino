/*
      Title: Simple Switch Timer
      Library: sstimer.ino
      Description: 
      Created Date: January 17, 2015
      Created By: Rolly Falco Villacacan
      Released into the public domain.
      http://www.mvsadnik.com/microcontrollers/
      https://www.facebook.com/groups/pinoymikrocontrollerscommunity/
      https://www.facebook.com/pages/Pinoy-Mikro-Controllers-

Community/1397572657207414
*/

#include <sstimer.h>

//WATER_PUMP SETUP
int PIN_NO1 = 13;
long unsigned OFF_DURATION = 500; //in milliseconds
long unsigned ON_DURATION = 500; //in milliseconds

//LIGHTHING SETUP
int PIN_NO2 = 12;
long unsigned OFF_DURATION2 = 1000; //in milliseconds
long unsigned ON_DURATION2 = 1000; //in milliseconds


sstimer WATER_PUMP(PIN_NO1, ON_DURATION, OFF_DURATION); //create instance for water pump
sstimer LIGHTHING(PIN_NO2, ON_DURATION2, OFF_DURATION2);//create instance for lighting

void setup(){
//...  
}


void loop(){
//...
WATER_PUMP.startsstimer();
LIGHTHING.startsstimer();
//..  
}


