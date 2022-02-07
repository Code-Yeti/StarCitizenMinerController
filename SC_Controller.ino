// Star Citizen Mining Controller

// Use Joystick Throttle for lazer
// Buttons to map to Alt+1/2/3 keys

// Joystick Library: https://github.com/MHeironimus/ArduinoJoystickLibrary

#include "Keyboard.h"
#include <Joystick.h>

Joystick_ Joystick;

int Throttle_ = 0;       

int Button1Pin = 5;
int Button2Pin = 7;
int Button3Pin = 9;

const bool initAutoSendState = true; 

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  Joystick.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

// Key Presses - Minging Modules
// Maybe change to controller buttons and remap in game?

// ALT+1
if(digitalRead(Button1Pin) == HIGH){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('1');
  delay(100);
  Keyboard.releaseAll();
}
// ALT+2
if(digitalRead(Button2Pin) == HIGH){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('2');
  delay(100);
  Keyboard.releaseAll();
}
// ALT+3
if(digitalRead(Button3Pin) == HIGH){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('3');
  delay(100);
  Keyboard.releaseAll();
}


// Mining Lazer
Throttle_ = analogRead(A1);
Throttle_ = map(Throttle_,1023,0,255,0);         
Joystick.setThrottle(Throttle_);     

delay (50);
}
