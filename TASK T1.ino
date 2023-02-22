// C++ code
//

const byte temp = A0;

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(temp, INPUT);
  Serial.begin(9600);
}

void loop()
{
  float temp = analogRead(temp);
 
  
  temp = (double)temp / 1024; 
  temp = ((temp * 5) - 0.5)*100; 
   
  

  Serial.print("Temperature : ");
  Serial.println(temp);
  
  if(temp>50){
  	digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    delay(1000);
    
  }
}
