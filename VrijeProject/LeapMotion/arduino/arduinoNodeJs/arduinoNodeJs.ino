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
  servo_left.attach(4);
  servo_right.attach(5);

  bluetooth.begin(115200); // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");    // Print three times individually
  bluetooth.print("$");
  bluetooth.println("$");          // Enter command mode
  delay(100);                    // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N"); // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600); // Start bluetooth serial at 9600
}

void loop()
{
//  while (Serial.available())
//  {
//    //Recieve data from Node and write it to a String
//    char inChar = (char)Serial.read();
//    if (inChar == 'f')
//    {
//      servo_left.write(100);
//      servo_right.write(80);
//    }
//    if (inChar == 'b')
//    {
//      servo_left.write(80);
//      servo_right.write(100);
//    }
//    if (inChar == 'l')
//    {
//      servo_left.write(80);
//      servo_right.write(80);
//    }
//    if (inChar == 'r')
//    {
//      servo_left.write(100);
//      servo_right.write(100);
//    }
//    if (inChar == 's')
//    {
//      servo_left.write(90);
//      servo_right.write(90);
//    }
//    else
//    {
//      inputString += inChar;
//    }
//  }

  if (bluetooth.available()) // If the bluetooth sent any characters
  {   
    // Recieve data from Node and write it to a String
    char inChar = (char)Serial.read();
    if (inChar == 'f')
    {
      servo_left.write(100);
      servo_right.write(80);      
      Serial.print("f");
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
