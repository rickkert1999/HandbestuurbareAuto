// add servo library
#include <Servo.h>
Servo servo_left;
Servo servo_right;

// Read vars
String inputString = ""; // a string to hold incoming data

void setup()
{
  // initialize serial:
  Serial.begin(9600);
  // define te servo signal pin
  servo_left.attach(2);
  servo_right.attach(3);
}

void loop()
{
  // Recieve data from Node and write it to a String
  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    if (inChar == 'f')
    {
      servo_left.write(100);
      servo_right.write(80);
    }
    if (inChar == 'b')
    {
      servo_left.write(80);
      servo_right.write(100);
    }
    if (inChar == 'l')
    {
      servo_left.write(80);
      servo_right.write(80);
    }
    if (inChar == 'r')
    {
      servo_left.write(100);
      servo_right.write(100);
    }
    if (inChar == 's')
    {
      servo_left.write(90);
      servo_right.write(90);
    }
    else
    {
      inputString += inChar;
    }
  }
  delay(50); // give the Arduino some breathing room.
}
