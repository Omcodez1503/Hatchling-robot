#include <Arduino.h>
#include <ESP32Servo.h>
#include <TurtleReceiver.h>
// put function declarations here:
Servo servo1;  // create servo object to control a servo

void setup() {
  // put your setup code here, to run once:
 servo1.attach(36, 1000, 2000);  // attaches the servo on pin 36 to the servo object
 servo1.setPeriodHertz(50);  // Analog servos run at ~50 Hz updates
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:

  
