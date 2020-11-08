// add library's
#include <Servo.h>
#include <SoftwareSerial.h>

Servo servo_left;
Servo servo_right;

int bluetoothTx = 2; // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3; // RX-I pin of bluetooth mate, Arduino D3

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

// Read vars
String inputString = ""; // a string to hold incoming data

void setup()
{
  // initialize serial:
  Serial.begin(9600);
  // define te servo signal pin
  servo_left.attach(5);
  servo_right.attach(4);

  // The Bluetooth Mate defaults to 115200bps 
  bluetooth.begin(115200);
}

void loop()
{
  while (bluetooth.available()) // While the bluetooth sent any characters
  {   
    // Recieve data from Node and write it to a String
    char inChar = (char)bluetooth.read();
    if (inChar == 'f')
    {
      servo_left.write(103);
      servo_right.write(80);      
    }
    if (inChar == 'b')
    {
      servo_left.write(80);
      servo_right.write(103);    
    }
    if (inChar == 'r')
    {
      servo_left.write(100);
      servo_right.write(100);
    } 
    if (inChar == 'l')
    {
      servo_left.write(83);
      servo_right.write(83);
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
