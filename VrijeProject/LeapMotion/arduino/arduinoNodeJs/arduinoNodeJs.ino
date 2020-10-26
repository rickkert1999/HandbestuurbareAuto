// LED vars 
const int ledPin = 13;
const int pwmPin = 3;


// LED read vars
String inputString = "";        // a string to hold incoming data
boolean toggleComplete = false; // whether the string is complete
boolean pwmComplete = false;

void setup()
{
    // initialize serial:
    Serial.begin(9600);
     // init LEDS
  pinMode(ledPin,OUTPUT);
  pinMode(pwmPin,OUTPUT);
  digitalWrite(ledPin,0);
  analogWrite(pwmPin,0);

    pinMode(LED_BUILTIN, OUTPUT);

}

void loop()
{
    // Recieve data from Node and write it to a String
    while (Serial.available() && toggleComplete == false && pwmComplete == false)
    {
        char inChar = (char)Serial.read();
        if (inChar == 'f')
        {
          digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(1000);                       // wait for a second
          digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
          delay(1000);                       // wait for a second 
          digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(1000);                       // wait for a second
          digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
          delay(1000);                       // wait for a second 
        }
        else
        {
            inputString += inChar;
        }
    }
    delay(50); // give the Arduino some breathing room.
}

int stringToInt()
{
    char charHolder[inputString.length() + 1];
    inputString.toCharArray(charHolder, inputString.length() + 1);
    inputString = "";
    int _recievedVal = atoi(charHolder);
    return _recievedVal;
}
