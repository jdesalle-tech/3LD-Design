#include <Stepper.h>;


// pushbutton pin
const int buttonPin = 5;

const int STEPS = 255;
Stepper stepper(STEPS, 8, 9, 10, 11);


//create a variable to store a counter and set it to 0
int counter = 0;

unsigned long last_button_time = 0;   //for aving last millis 



void setup(){
  pinMode(buttonPin, INPUT);
  stepper.setSpeed(100);
}


void loop(){
  bool buttonState;   // local variable to hold the pushbutton states

  //read the digital state of buttonPin with digitalRead() function and store the           //value in buttonState variable
  buttonState = digitalRead(buttonPin);

  //if the button is pressed increment counter and wait a tiny bit to give us some          //time to release the button
  if(buttonState == HIGH && millis() - last_button_time > 200){ // light the LED  
    last_button_time = millis();
    counter++;
    stepper.step(STEPS/8);    //90° degrees 
  }
}
