/*
      Title: Simple Switch Timer
      Library: sstimer.h
      Description: 
      Created Date: January 17, 2015
      Created By: Rolly Falco Villacacan
      Released into the public domain.
      http://www.mvsadnik.com/microcontrollers/
      https://www.facebook.com/groups/pinoymikrocontrollerscommunity/
      https://www.facebook.com/pages/Pinoy-Mikro-Controllers-Community/1397572657207414
*/

#ifndef 	sstimer_h
#define 	sstimer_h
#include 	"arduino.h"

class sstimer 
{     
  public: 
    sstimer(int PIN,long unsigned ON_DURATION, long unsigned OFF_DURATION);
    void check();
  
  private:   
    unsigned long _tsaved;
    boolean _PIN_STATUS;
    int _PIN;
    long unsigned _ON_DURATION;
    long unsigned _OFF_DURATION;   
};
#endif