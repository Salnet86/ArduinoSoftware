#include <ESP8266WiFi.h>
#include <Servo.h>

const char* ssid = "NOME_WIFI";
const char* password = "PASSWORD_WIFI";

WiFiServer server(80);

#define TRIG_PIN D1
#define ECHO_PIN D2
#define SERVO_PIN D3
#define PASSO 10
#define SOGLIA 50
#define PASSI (180/PASSO + 1)

Servo servo;
int mappa[PASSI];

long misuraUltrasuoni() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long durata = pulseIn(ECHO_PIN, HIGH);
  long distanza = durata * 0.034 / 2;
  return distanza;
}

void setup() {
  Serial.begin(115200);
  servo.attach(SERVO_PIN);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnesso al WiFi");
  
  server.begin();
}

void loop() {
  // Aggiorna la mappa
  int indice = 0;
  for(int angolo=0; angolo<=180; angolo+=PASSO){
    servo.write(angolo);
    delay(500);
    long d = misuraUltrasuoni();
    if(d < SOGLIA) mappa[indice] = 1;
    else mappa[indice] = 0;
    indice++;
  }

  // Attendi client web
  WiFiClient client = server.available();
  if(client){
    String response = "[";
    for(int i=0;i<PASSI;i++){
      response += String(mappa[i]);
      if(i<PASSI-1) response += ",";
    }
    response += "]";

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Connection: close");
    client.println();
    client.println(response);
    delay(100);
    client.stop();
  }
}
