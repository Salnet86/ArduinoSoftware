// Radar Arduino - Processing
// Autore rifatto da Martina Mirandi
// Versione corretta e leggibile
import processing.serial.*; // libreria per la comunicazione seriale
Serial myPort; // oggetto seriale

// Variabili per i dati ricevuti da Arduino
String data = "";
String angleStr = "";
String distanceStr = "";
String noObject;
float pixDistance;
int iAngle, iDistance;

// Font
PFont orcFont;

void setup() {
  size(1920, 1080); // cambiare in base alla risoluzione dello schermo
  smooth();
  // Inizializza la comunicazione seriale (modificare la porta COM)
  myPort = new Serial(this, "COM4", 9600);
  myPort.bufferUntil('.'); // legge i dati fino al carattere '.[span_2](start_span)'[span_2](end_span)
  orcFont = createFont("OCRAExtended-30.vlw", 30);
  textFont(orcFont);
}

void draw() {
  background(98, 245, 31); // sfondo verde
  drawRadar();
  drawLine();
  drawObject();
  drawText();
}

// Funzione che legge i dati seriali da Arduino
void serialEvent(Serial myPort) {
  data = myPort.readStringUntil('.');
  if (data != null) {
    data = data.substring(0, data.length() - 1); // rimuove il punto finale
    int commaIndex = data.indexOf(',');
    if (commaIndex > 0) {
      angleStr = data.substring(0, commaIndex);
      distanceStr = data.substring(commaIndex + 1);
      iAngle = int(angleStr);
      iDistance = int(distanceStr);
    }
  }
}

// Disegna il radar
void drawRadar() {
  pushMatrix();
  translate(width / 2, height - height * 0.074f); // centro radar
  noFill();
  strokeWeight(2);
  stroke(98, 245, 31);
  // Disegna gli archi concentrici
  arc(0, 0, width * 0.938f, width * 0.938f, PI, TWO_PI);
  arc(0, 0, width * 0.73f, width * 0.73f, PI, TWO_PI);
  arc(0, 0, width * 0.521f, width * 0.521f, PI, TWO_PI);
  arc(0, 0, width * 0.313f, width * 0.313f, PI, TWO_PI);
  // Disegna le linee degli angoli
  line(-width / 2, 0, width / 2, 0);
  for (int a = 30; a <= 150; a += 30) {
    float rad = radians(a);
    line(0, 0, -width / 2 * cos(rad), -width / 2 * sin(rad));
  }
  popMatrix();
}

// Disegna gli oggetti rilevati dal sensore
void drawObject() {
  if (iDistance > 0 && iDistance < 40) {
    pixDistance = iDistance * (height * 0.025f); // scala da cm a pixel
    pushMatrix();
    translate(width / 2, height - height * 0.074f);
    stroke(255, 10, 10);
    strokeWeight(9);
    float rad = radians(iAngle);
    line(pixDistance * cos(rad), -pixDistance * sin(rad),
         (width/2) * cos(rad), -(width / 2) * sin(rad));
    popMatrix();
  }
}

// Disegna la linea del radar
void drawLine() {
  pushMatrix();
  translate(width / 2, height - height * 0.074f);
  stroke(30, 250, 60);
  strokeWeight(9);
  float rad = radians(iAngle);
  line(0, 0, height * 0.12f * cos(rad), -height * 0.12f * sin(rad));
  popMatrix();
}

// Disegna il testo sullo schermo
void drawText() {
  pushMatrix();
  noStroke();
  if (iDistance > 40) {
    noObject = "Fuori intervallo";
  } else {
    noObject = "Nell'intervallo";
  }
  fill(0);
  rect(0, height - height * 0.0648f, width, height * 0.0648f);
  fill(98, 245, 31);
  textSize(25);
  text("10 cm", width * 0.615f, height - height * 0.0833f);
  text("20 cm", width * 0.719f, height - height * 0.0833f);
  text("30 cm", width * 0.823f, height - height * 0.0833f);
  text("40 cm", width * 0.927f, height - height * 0.0833f);
  textSize(40);
  text("Oggetto: " + noObject, width * 0.125f, height - height * 0.0277f);
  text("Angolo: " + iAngle + "°", width * 0.52f, height - height * 0.0277f);
  text("Distanza: ", width * 0.74f, height - height * 0.0277f);
  if (iDistance < 40) {
    text(iDistance + " cm", width * 0.775f, height - height * 0.0277f);
  }
  popMatrix();
}
