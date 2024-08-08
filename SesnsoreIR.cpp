

#include <IRremote.h>

int pinIRremote = 5;
IRrecv receiver(pinIRremote);
decode_results results;

void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn();
}

void loop()
{
  if (receiver.decode(&results))
  { 
    Serial.println(results.value);
    receiver.resume();
  }
}




