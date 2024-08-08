#define trigPin 6
#define echo1Pin 5
#define echo2Pin 4
#define echo3Pin 3
#define echo4Pin 2

long durata, cm1,cm2,cm3,cm4;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echo1Pin, INPUT);
  pinMode(echo2Pin, INPUT);
  pinMode(echo3Pin, INPUT);
  pinMode(echo4Pin, INPUT);
}

void loop() {
  trig();
  durata = pulseIn(echo1Pin, HIGH);
  cm1 = durata / 58;
  delayMicroseconds(50);
  trig();
  durata = pulseIn(echo2Pin, HIGH);
  cm2 = durata / 58;
  delayMicroseconds(50);
  trig();
  durata = pulseIn(echo3Pin, HIGH);
  cm3 = durata / 58;
  delayMicroseconds(50);
  trig();
  durata = pulseIn(echo4Pin, HIGH);
  cm4 = durata / 58;
  delayMicroseconds(50);

  Serial.print("Cm1 = ");
  Serial.println(cm1);
  Serial.println();
  Serial.print("Cm2 = ");
  Serial.println(cm2);
  Serial.println();
  Serial.print("Cm3 = ");
  Serial.println(cm3);
  Serial.println();
  Serial.print("Cm4 = ");
  Serial.println(cm4);
  Serial.println();
}

void trig () {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}