// Definiamo i pin a cui sono collegati i LED
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // Modifica con i tuoi pin
const int numLeds = 11; // Numero di LED

void setup() {
  // Impostiamo tutti i pin come uscite
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);  // Spegniamo tutti i LED all'inizio
  }
}

void loop() {
  // Sequenza di accensione dei LED
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);  // Accendiamo il LED corrente
    delay(200); // Tempo di attesa tra ogni LED acceso
    digitalWrite(ledPins[i], LOW);   // Spegniamo il LED corrente
  }
  
  // Opzionale: invertire la sequenza (accendere i LED in ordine inverso)
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);  // Accendiamo il LED corrente
    delay(200); // Tempo di attesa tra ogni LED acceso
    digitalWrite(ledPins[i], LOW);   // Spegniamo il LED corrente
  }
  
  delay(1000); // Pausa prima di ripetere la sequenza
}
