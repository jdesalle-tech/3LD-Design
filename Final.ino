/*
 Stepper Motor Control - one revolution
 Wait for button press and rotates to stop unti next button press.
 */

#include <Stepper.h>
#include <CapacitiveSensor.h>
const int stepsPerRevolution = 255;  // change this to fit the number of steps per revolution for your motor
int capbegin = 0;                    
//int pins for pushbutton for lid rotation
int pushpin = 5; //Input pin for pushbutton
int motorpwr = 7; 
int val = 0;

//capacitance sensor int

int treshold = 500; // the minimum value for turning the LED on
int ledPin = 12;


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2);  

void setup() {
  //Stepper Setup
  pinMode(pushpin, INPUT);   //declare pusbutton as input
  
  // Motor setup
  myStepper.setSpeed(60); //set the speed at 60 rpm:
  Serial.begin(9600);     //set the speed at 60 rpm:
  //Stepper Setup End

  //Capacitance Sensor Setup
 cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
  //Capacitance Sensor End
}

void capacitance_sensor()
{
  //Serial.print("Begin");
   long start = millis();
  long sensorValue =  cs_4_2.capacitiveSensor(30);


  //Serial.print(millis() - start);        // check on performance in milliseconds
  //Serial.print("\t");                    // tab character for debug windown spacing

  //Serial.print(sensorValue);                  // print sensor output 1
  //Serial.print("\n");

  if (sensorValue > treshold) {
    digitalWrite(ledPin, HIGH);
    delay(1500);                             // arbitrary delay to limit data to serial port 
    digitalWrite(ledPin, LOW);
   Serial.print("Pills Taken");
   loop();
  }
  else {
    capacitance_sensor();
  }

  
}
void loop() {
 
  //motor step function w/ pushbutton  7
    
  val = digitalRead(pushpin); //read input button value
  
    if (digitalRead(pushpin) == HIGH) {
    //step one revolution  in one direction:
    Serial.println("turning");
    myStepper.step(stepsPerRevolution);
    delay(1500);  
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    Serial.println("done turning");
    capacitance_sensor();
    return; }
    else if (digitalRead(pushpin) == LOW) {
    return;}

    
 
    

  }
  
