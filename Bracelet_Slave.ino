char value; 
int ledpin = 13;
void setup() {
  pinMode(ledpin, OUTPUT);         
  Serial.begin(9600);              
  digitalWrite(ledpin, LOW); // start with the LED off
}
void loop() {
  if( Serial.available() ) // check for serial data
  {
    value = Serial.read(); // load data into 'value' variable
  }
  if( value == '1' )   // if '1' was received
  {
    digitalWrite(ledpin, HIGH);  // then turn ON the LED
  } else { 
    digitalWrite(ledpin, LOW); // otherwise turn it OFF
  }
}
