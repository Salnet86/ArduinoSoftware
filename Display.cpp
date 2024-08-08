#define COMMON_ANODE 1
#define COMMON_CATODE 0
// -----------------------------------------------------------------
// Definisco la mappatura tra pin e segmenti
// -----------------------------------------------------------------
int segA = 6;   // Undicesimo PIN del display 7Segment x 4
int segB = 2;   // Settimo PIN del display 7Segment x 4
int segC = 10;  // Quarto PIN del display 7Segment x 4
int segD = 12;  // Secondo PIN del display 7Segment x 4
int segE = 13;  // Primo PIN del display 7Segment x 4
int segF = 5;   // Decimo PIN del display 7Segment x 4
int segG = 9;   // Quinto PIN del display 7Segment x 4
int segDP = 11; // Terzo PIN del display 7Segment x 4

int digit1 = 7; // Dodicesimo PIN - PWM che Accende il primo digit
int digit2 = 4; // Nono PIN - PWM che Accende il secondo digit 
int digit3 = 3; // Ottavo PIN - PWM che Accende il terzo digit 
int digit4 = 8; // Sesto PIN - PWM che Accende il quarto digit

// Stesse define ma ordinate per PIN del display
//  int segE = 13;  // Primo PIN
//  int segD = 12;  // Secondo PIN 
//  int segDP = 11; // Terzo PIN
//  int segC = 10;  // Quarto PIN
//  int segG = 9;   // Quinto PIN
//  int digit4 = 8; // Sesto PIN - PWM che Accende il quarto digit
//  int segB = 2;   // Settimo PIN
//  int digit3 = 3; // Ottavo PIN - PWM che Accende il terzo digit 
//  int digit2 = 4; // Nono PIN - PWM che Accende il secondo digit 
//  int segF = 5;   // Decimo PIN
//  int segA =  6;  // Undicesimo PIN
//  int digit1 = 7; // Dodicesimo PIN - PWM che Accende il primo digit

#include "SevSeg.h"

// Crea un'istanza dell'oggetto
SevSeg sevseg;

void setup() 
{
  // Inizializzo i PIN
  sevseg.Begin(COMMON_CATODE,digit1,digit2,digit3,digit4,
               segA,segB,segC,segD,segE,segF,segG,segDP);
  // Imposto la luminosità (valore da 0 a 100)
  sevseg.Brightness(90);
}

void loop() 
{
    // Mostra il valore
    sevseg.PrintOutput();
    
    // Aggiorna il numero visualizzato. Il secondo argomento corrisponde 
    // alla posizione della virgola. Se metto un valore superiore a 4 riempie
    // il numero con degli zeri iniziali
    int Secondi=millis()/1000 % 10000;
    sevseg.NewNum(Secondi,(byte) 4);
}