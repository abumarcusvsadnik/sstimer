/*
      Title: Simple Switch Timer
      Library: sstimer.cpp
      Description: 
      Created Date: January 17, 2015
      Created By: Rolly Falco Villacacan
      http://www.mvsadnik.com/microcontrollers/
      https://www.facebook.com/groups/pinoymikrocontrollerscommunity/
      https://www.facebook.com/pages/Pinoy-Mikro-Controllers-Community/1397572657207414
*/

#include "sstimer.h"
#include "arduino.h"


sstimer::sstimer(int PIN,long unsigned ON_DURATION, long unsigned OFF_DURATION)
{ 
 _tsaved = 0; 
 _PIN_STATUS = false;  
 _ON_DURATION = ON_DURATION;
 _OFF_DURATION = OFF_DURATION;
 _PIN = PIN;
 pinMode(_PIN, OUTPUT); 
}

void sstimer::check()
{   
  if(!_PIN_STATUS)
      {            
        if(_OFF_DURATION <= millis() - _tsaved)
          {
            _PIN_STATUS = !_PIN_STATUS;
            _tsaved = millis();              
          }
               digitalWrite(_PIN,LOW);      
      }  
   else
      {  
        if(_ON_DURATION <= millis() - _tsaved)
          {
            _PIN_STATUS = !_PIN_STATUS;
            _tsaved = millis();
          }   
               digitalWrite(_PIN,HIGH);            
      }     
}
