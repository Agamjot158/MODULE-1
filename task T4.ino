const byte Led = 12;
const byte timer_Led = 10;
const byte button1 = 2;
const byte button2 = 3;
const byte button3 = 8;
bool LedState = false;
int timer1_compare_match = 31249;

void setup() {
 
  Serial.begin(9600);
  pinMode(button2, INPUT);
  pinMode(button1, INPUT);
  pinMode(button3, INPUT);      
  pinMode(Led, OUTPUT);
  pinMode(timer_Led, OUTPUT);
  

  attachInterrupt(digitalPinToInterrupt (button1), button_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(button2), button_2, CHANGE);
 
  PCICR |= B00000001;
  PCMSK0 |= B00000001;
 
  TCCR1A = 0;   
  TCCR1B = 0;   
  TCNT1 = timer1_compare_match;
  TCCR1B |= (1<< CS12);   //1

  
  TIMSK1 = (1 << OCIE1A);

  
  sei(); 
  
}

void loop() {

  delay(50);
 
}

void button_2()
{
  Serial.println("Interrupt detected: Button #2 ");
  LedState = !LedState;
  digitalWrite(Led, LedState);
}

void button_1()
{
  Serial.println("Interrupt detected: Button #1");
  LedState = !LedState;
  digitalWrite(Led, LedState);
  
}

ISR(PCINT0_vect){
  
  Serial.println("Interrupt detected: Button #3");
  LedState = !LedState;
  digitalWrite(Led, LedState);
}
  
ISR(TIMER1_COMPA_vect)
{
  TCNT1 = timer1_compare_match;
  digitalWrite(timer_Led, digitalRead(timer_Led) ^ 1);
}
