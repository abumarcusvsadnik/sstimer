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


sstimer::sstimer(int PIN,long unsigned ON_DURATION, long unsigned OFF_DURATION, int NUM_CYCLES)
{ 
	_tsaved = 0;
	_curCycle = 0;
	_PIN_STATUS = false;  
	_PIN = PIN;
	_ON_DURATION = ON_DURATION;
	_OFF_DURATION = OFF_DURATION;
	_NUM_CYCLES = NUM_CYCLES;
	pinMode(_PIN, OUTPUT);
	digitalWrite(_PIN, LOW);	
}

void sstimer::restart()
{
	_tsaved = 0;
	_curCycle = 0;
	_PIN_STATUS = false;
	digitalWrite(_PIN, LOW);
}

void sstimer::check()
{
  if(_curCycle < _NUM_CYCLES || _NUM_CYCLES == 0) {
		if(!_PIN_STATUS) {            
			if(_OFF_DURATION <= millis() - _tsaved) {
				_PIN_STATUS = !_PIN_STATUS;
				_tsaved = millis();              
			}
			digitalWrite(_PIN, LOW);
		}  
		else {  
			if(_ON_DURATION <= millis() - _tsaved) {
				_PIN_STATUS = !_PIN_STATUS;
				_tsaved = millis();
				_curCycle++;
			}   
			digitalWrite(_PIN, HIGH);
		}
	}
	else {
		digitalWrite(_PIN,LOW);
	}
}

