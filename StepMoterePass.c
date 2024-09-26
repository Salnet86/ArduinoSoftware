/*  Esempio di controllo del Motore stepper
 *      
 *  by Michele Aurelio http://www.arduinofacile.it
 *  
 */

// definizione dei PIN
const int stepPin = 3; 
const int dirPin = 4; 
const int stepForRevolution = 200;
const int coeffSpeedLOW = 2000;
const int coeffSpeedHigh = 1000;

 
void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}


void loop() {
  //Motore in direzione oraria
  digitalWrite(dirPin,HIGH);
  
  // Due giri veloci in avanti
  for(int x = 0; x < 2*stepForRevolution; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(coeffSpeedHigh); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(coeffSpeedHigh); 
  }
  delay(1000); // pausa di un secondo

  //Motore in direzione antioraria
  digitalWrite(dirPin,LOW);
  
  // Cinque giri lenti nell'altra direzione 
  for(int x = 0; x < 5 * stepForRevolution; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(coeffSpeedLOW);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(coeffSpeedLOW);
  }
  delay(1000);
}
