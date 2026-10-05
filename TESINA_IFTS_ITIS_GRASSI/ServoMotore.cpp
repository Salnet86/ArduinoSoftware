// Include la libreria Servo
#include <Servo.h>


// Definisce i pin Trig ed Echo del sensore a ultrasuoni
const int trigPin = 10;
const int echoPin = 11;


// Variabili per la durata e la distanza
long durata;
int distanza;


Servo myServo; // Crea un oggetto servo per controllare il servomotore


void setup() {
  pinMode(trigPin, OUTPUT); // Imposta il TrigPin come OUTPUT
  pinMode(echoPin, INPUT); // Imposta l'EchoPin come INPUT
  Serial.begin(9600); // Avvia la comunicazione seriale
  myServo.attach(12); // Collega il servomotore al pin 12
}


void loop() {
  // Ruota il servomotore da 15 a 165 gradi
  for (int i = 15; i <= 165; i++) {
    myServo.write(i);
    delay(30);
    distanza = calcolaDistanza();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distanza);
    Serial.print(".");
  }
  
  // Ruota il servomotore da 165 a 15 gradi
  for (int i = 165; i > 15; i--) {
    myServo.write(i);
    delay(30);
    distanza = calcolaDistanza();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distanza);
    Serial.print(".");
  }
}


// Funzione per il calcolo della distanza
int calcolaDistanza() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Imposta il trigPin su HIGH per 10 microsecondi
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Legge il tempo di ritorno dell'onda sonora
  durata = pulseIn(echoPin, HIGH);
  
  // Calcola la distanza (velocità del suono 0.034 cm/us)
  distanza = durata * 0.034 / 2;
  return distanza;
}

