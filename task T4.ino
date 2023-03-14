const byte Led = 12;
const byte timer_Led = 10;
const byte button1 = 2;
const byte button2 = 3;
const byte button3 = 4;
bool LedState = false;
int timer1_compare_match;

void setup() {
 
  Serial.begin(9600);
  pinMode(button2, INPUT);
  pinMode(button1, INPUT);
  pinMode(button3, INPUT);      
  pinMode(Led, OUTPUT);
  pinMode(timer_Led, OUTPUT);
  

  attachInterrupt(digitalPinToInterrupt (button1), button_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(button2), button_2, CHANGE);
 
  
    TCCR1A = 0;

 
  TCCR1B &= ~(1<<WGM13);   
  TCCR1B |= (1<< WGM12);   

  TCCR1B |= (1<< CS12);   //1
  TCCR1B &= ~(1<<CS11);   //0
  TCCR1B |= (1<< CS10);   //1

  
  TCNT1 = t1_load;
  OCR1A = t1_compare;

  
  TIMSK1 = (1 << OCIE1A);

  
  sei(); 
  
}

void loop() {

  delay(50);
 
}

void button_2()
{
  Serial.println("Interrupt detected: Button #2 ");
  Serial.println("");
  LedState = !LedState;
  digitalWrite(Led, LedState);
}

void button_1()
{
  Serial.println("Interrupt detected: Button #1");
  LedState = !LedState;
  digitalWrite(Led, LedState);
  Serial.println("");
  Serial.println("Interrupt detected: Button #3");
  
}

void Interrupt3(){
  
  Serial.println("Interrupt detected: Button #3");
  LedState = !LedState;
  digitalWrite(Led, LedState);
}
  
ISR(TIMER1_COMPA_vect)
{
  TCNT1 = timer1_compare_match;
  digitalWrite(timer_Led, digitalRead(timer_Led) ^ 1);
}
