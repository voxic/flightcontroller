#include "Joystick.h"

Joystick_ Joystick;

  int xAxis_ = 0;
  int RxAxis_ = 0;
  int yAxis_ = 0;                 
  int RyAxis_ = 0;
  int throttle=0;
  void setup()
{
  //Setup all buttons as inputs with PULLUP
  for(int i = 3;i < 13;i++){
    pinMode(i, INPUT_PULLUP);
  }
  
  Joystick.begin();
  //Serial.begin(9600); //Start serial monitoring
}
void loop()
{
      //Check button states
      checkButtons();

      //Read and set X Axis
      xAxis_ = analogRead(A2);
      //Serial.print("X: ");
      //Serial.println(xAxis_);
      xAxis_ = map(xAxis_,0,1023,255,0); //Map and Reverse the axis
      Joystick.setXAxis(xAxis_);

      //Read and set Y Axis
      yAxis_ = analogRead(A1);
      //Serial.print("y: ");
      //Serial.println(yAxis_);
      yAxis_ = map(yAxis_,0,1023,255,0); //Map and Reverse the axis
      Joystick.setYAxis(yAxis_);

      // Read and set Throttle
      throttle = analogRead(A3);
      //Serial.print("t: ");
      //Serial.println(throttle);
      throttle = map(throttle,0,1023,0,255); //Map the axis
      Joystick.setThrottle(throttle);
      
      
      Joystick.sendState(); //Send the new state to computer

      //Slow eveything down a bit
      delay(10);
}

void checkButtons(void){

  //Loop over each pin and set Button to the oposite (Pullup)
  for(int i = 3;i < 13;i++){
    Joystick.setButton(i, !digitalRead(i));
  }
    
  
}
