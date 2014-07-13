int enable = 0;
int servo = 1;
int poten = 2;
int x(0);
unsigned long time = 0 ; 


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
    pinMode(enable, INPUT);    
    pinMode(servo, OUTPUT);  
    pinMode(poten,  INPUT);   
}

// the loop routine runs over and over again forever:
void loop() {
  
  time = map(analogRead(poten),0,1023,1000,2000);
  
  if (digitalRead(enable)){
    digitalWrite(servo,1);
    delayMicroseconds(time);
    digitalWrite(servo,0);
    delayMicroseconds(20000-time);
  }
  else{
    digitalWrite(servo,1);
    delayMicroseconds(1000);
    digitalWrite(servo,0);
    delayMicroseconds(20000);
    
  }

}
