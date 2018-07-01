/*
  Controlling a servo position using a potentiometer (variable resistor)
  by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

  modified on 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
#define numpot 3
#define servo_start 8

Servo myservo[3];  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int analog_val[numpot], servo_val[numpot];    // variable to read the value from the analog pin

void setup() {
  for (int cntr = 0; cntr < numpot ; cntr++)
  {
    myservo[cntr].attach(cntr + servo_start);  // attaches the servo on pin 9 to the servo object
  }

  Serial.begin(9600);
}

void loop() {
  for (int cntr = 0; cntr < numpot ; cntr++)
  {
    analog_val[cntr] = analogRead(cntr);            // reads the value of the potentiometer (value between 0 and 1023)
    servo_val[cntr] = map(analog_val[cntr], 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myservo[cntr].write(servo_val[cntr]);                  // sets the servo position according to the scaled value
    Serial.print("cntr : ");
    Serial.print(cntr);
    Serial.print("| analog_val : ");
    Serial.print(analog_val[cntr]);
    Serial.print("| servo_val :");
    Serial.print(servo_val[cntr]);
    Serial.print(" >> ");
    delay(15);                           // waits for the servo to get there
  }
  Serial.println("");
}

