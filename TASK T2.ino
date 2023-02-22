// C++ code
//

const uint8_t BTN_PIN = 2; // Button pin number
const uint8_t LED_PIN = 8; // LED pin number

//variables for LED and Button 
uint8_t buttonPrevState = HIGH; 
uint8_t ledState = LOW;


void setup()
{
  //Button pin is used as input 
  pinMode(BTN_PIN, INPUT_PULLUP);
  //LED pin is used as output
  pinMode(LED_PIN, OUTPUT);
  
  //interrupt:
    attachInterrupt(0, TOGGLE, CHANGE);
  
  //initializing serial communication with a baud rate of 9600
  Serial.begin(9600);
}

void loop()
{
 delay(10); 
  
}

void TOGGLE(){
	buttonPrevState = digitalRead(2);
  	digitalWrite(8, buttonPrevState);
    Serial.println(buttonPrevState);
}
