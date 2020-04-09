/*
 Stepper Motor Control - one revolution
 Wait for button press and rotates to stop unti next button press.
 */

#include <Stepper.h>

const int stepsPerRevolution = 255;  // change this to fit the number of steps per revolution for your motor
                    
//int pins for pushbutton for lid rotation
int pushpin = 5; //Input pin for pushbutton
int motorpwr = 7;
int val = 0;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  
  pinMode(pushpin, INPUT);   //declare pusbutton as input
  
  // Motor setup
  myStepper.setSpeed(60); //set the speed at 60 rpm:
  Serial.begin(9600);     //set the speed at 60 rpm:
}

void loop() {
 
  //motor step function w/ pushbutton
  val = digitalRead(pushpin); //read input button value
    if (digitalRead(pushpin) == HIGH) {
    myStepper.step(stepsPerRevolution);
    delay(1500);  
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    return; }
    else if (digitalRead(pushpin) == LOW) {
    return;}
    
    //step one revolution  in one direction:
    Serial.println("turning");
    

  }
  
