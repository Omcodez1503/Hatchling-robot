// import libraries here:
#include <Arduino.h>
#include <ESP32Servo.h>
#include <TurtleReceiver.h>
// put function declarations here:
Servo servo1;  // create servo object to control a servo
NetController controller; // creates controller object

 // Drivetrain variables
  // Motor 1
  int ENApin = 4;
  int IN1pin = 16;
  int IN2pin = 17;
  // Motor 2
  int ENBpin = 5;
  int IN3pin = 18;
  int IN4pin = 19;
 // Elevator Variables
  // Motor 3
  int IN3pin2 = 14;
  int IN4pin2 = 12;

void setup() {
  Serial.begin(115200);
  controller.controllerSetup();
  // put your setup code here, to run once:
  // Servo Setup
 servo1.attach(26, 1000, 2000);  // attaches the servo on pin 36 to the servo object
 servo1.setPeriodHertz(50);  // Analog servos run at ~50 Hz updates
 // Drivetrain
  // Motor 1
  pinMode(ENApin, OUTPUT);
  pinMode(IN1pin, OUTPUT);
  pinMode(IN2pin, OUTPUT);
  // Motor 2
  pinMode(ENBpin, OUTPUT);
  pinMode(IN3pin, OUTPUT);
  pinMode(IN4pin, OUTPUT);
 // Elevator
  // Motor 3
  pinMode(IN3pin2, OUTPUT);
  pinMode(IN4pin2, OUTPUT);
  analogWrite(ENApin,255);
  analogWrite(ENBpin,255);
}

void loop() {
  // put your main code here, to run repeatedly:
  // TEST CODE
  servo1.write(90);
  // Motor 1
  digitalWrite(IN1pin, LOW);
  digitalWrite(IN2pin, LOW);
  sleep(1);
  // Motor 2
  digitalWrite(IN3pin, LOW);
  digitalWrite(IN4pin, LOW);
  sleep(1);
  // Motor 3
  digitalWrite(IN3pin2, LOW);
  digitalWrite(IN4pin2, LOW);
  sleep(1);

  // Actual Code

  // Servo Code
    // Servo Open
  if(controller.getX() == true){
    servo1.write(90);
  }
    // Servo Close
  if(controller.getY() == true){
    servo1.write(45);
  }
  // Joystick Right
  if(controller.getJoy1X() > 0){
    int motorSpeed = map(controller.getJoy1X(), 0, 1, 70, 255);
    digitalWrite(IN1pin, HIGH);
    digitalWrite(IN2pin, LOW);
    digitalWrite(IN3pin, LOW);
    digitalWrite(IN4pin, LOW);
    analogWrite(ENApin, motorSpeed);
    analogWrite(ENBpin, motorSpeed);
  }

  // Joystick Left
  if(controller.getJoy1X() < 0){
    int motorSpeed = map(controller.getJoy1X(), 0, -1, 70, 255);
    digitalWrite(IN1pin, LOW);
    digitalWrite(IN2pin, LOW);
    digitalWrite(IN3pin, HIGH);
    digitalWrite(IN4pin, LOW);
    analogWrite(ENApin, motorSpeed);
    analogWrite(ENBpin, motorSpeed);
  }
  // Joystick Up
  if(controller.getJoy1Y() > 0){
    int motorSpeed = map(controller.getJoy1Y(), 0, 1, 70, 255);
    digitalWrite(IN1pin, HIGH);
    digitalWrite(IN2pin, LOW);
    digitalWrite(IN3pin, HIGH);
    digitalWrite(IN4pin, LOW);
    analogWrite(ENApin, motorSpeed);
    analogWrite(ENBpin, motorSpeed);
  }
  // Joystick Down
  if(controller.getJoy1Y() < 0){
    int motorSpeed = map(controller.getJoy1Y(), 0, -1, 70, 255);
    digitalWrite(IN1pin, LOW);
    digitalWrite(IN2pin, HIGH);
    digitalWrite(IN3pin, LOW);
    digitalWrite(IN4pin, HIGH);
    analogWrite(ENApin, motorSpeed);
    analogWrite(ENBpin, motorSpeed);
  }
  // Elevator Up
  if(controller.getA() == true){
    digitalWrite(IN3pin2, HIGH);
    digitalWrite(IN4pin2, LOW);
  }
  // Elevator Down
  if(controller.getB() == true){
    digitalWrite(IN3pin2, LOW);
    digitalWrite(IN4pin2, HIGH); 
  }
}

// put function definitions here:

  
