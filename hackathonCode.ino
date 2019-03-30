/*
  Stepper Motor Demonstration 1
  Stepper-Demo1.ino
  Demonstrates 28BYJ-48 Unipolar Stepper with ULN2003 Driver
  Uses Arduino Stepper Library

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

//Include the Arduino Stepper Library
#include <Stepper.h>

// Define Constants

// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 

//  Amount of Gear Reduction
const float GEAR_RED = 64;

// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

// Define Variables

// Number of Steps Required
int StepsRequired;

// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 8,9,10,11 
// Connected to ULN2003 Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-3-2-4 for proper step sequencing


//  THE BEGINNING OF OUR CODE THAT WAS ADDED


Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);


bool checker = false;
const int button1 = 12;
const int button2 = 13;
int buttonState1 = LOW;
int buttonState2 = LOW;
// Setup variable
void setup()
{
pinMode(button1, INPUT);
pinMode (button2, INPUT);
pinMode( buttonState1, INPUT);
pinMode( buttonState2, INPUT); 
// Nothing  (Stepper Library sets pins as outputs)
}

void loop()
{
  // Slow - 2-step CW sequence to observe lights on driver board
  steppermotor.setSpeed(10);    
  StepsRequired  =  4;
  steppermotor.step(StepsRequired);
  delay(500);
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);

if (buttonState1 == HIGH){
      checker =  true;
      }
else if ( buttonState2 == HIGH){
  checker = true;
 }
   // Rotate CW 1/2 turn slowly
if (buttonState1 == HIGH){
  StepsRequired  =  STEPS_PER_OUT_REV/2; 
  steppermotor.setSpeed(1000);   
  steppermotor.step(StepsRequired);
  checker = false;
  buttonState1 = LOW;
  steppermotor.setSpeed(0);
  delay(2000);
   }
  //Rotate CCW 1/2 turn quickly
if(buttonState2 == HIGH){
  StepsRequired  =  - STEPS_PER_OUT_REV/2;   
  steppermotor.setSpeed(1000);  
  steppermotor.step(StepsRequired);
  checker = false;
  buttonState2 = LOW;
  steppermotor.setSpeed(0);
  delay(2000);
}
}
