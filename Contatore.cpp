const int a = 3;
const int b = 4;
const int c = 5;
const int d = 6;
const int e = 7;
const int f = 8;
const int g = 9;
const int h = 10;
const int bottone=2;
int statoBottone;
int pulse;
int i;
const int periodo=500;
int j=0;

void numero(int n) {
  {
    switch(n)
    {
      case 0:

  digitalWrite (a, LOW);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  digitalWrite (h, LOW);
  break;
      case 1:
  digitalWrite (a, LOW);
  digitalWrite (b, HIGH);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, HIGH);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
  digitalWrite (h, LOW);
  break;
  case 2:
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, LOW);
  digitalWrite (h, HIGH);
  break;
  case 3:
  digitalWrite (a, LOW);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, LOW);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, LOW);
  digitalWrite (h, HIGH);
 break;
 case 4:
  digitalWrite (a, LOW);
  digitalWrite (b, HIGH);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, HIGH);
  digitalWrite (f, LOW);
  digitalWrite (g, HIGH);
  digitalWrite (h, HIGH);
  break;
  case 5:
  digitalWrite (a, LOW);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  digitalWrite (h, HIGH);
  break;
  case 6:
  digitalWrite (a, LOW);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, LOW);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  digitalWrite (h, HIGH);
  break;
  case 7:
  digitalWrite (a, LOW);
  digitalWrite (b, HIGH);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, LOW);
  digitalWrite (h, LOW);
  break;
  case 8:
  digitalWrite (a, LOW);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  digitalWrite (h, HIGH);
  break;
  case 9:
  digitalWrite (a, LOW);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, LOW);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  digitalWrite (h, HIGH);
  break;
      }
   }
 };

void setup() {
  Serial.begin(9600);
  pinMode (a, OUTPUT);
  pinMode (b, OUTPUT);
  pinMode (c, OUTPUT);
  pinMode (d, OUTPUT);
  pinMode (e, OUTPUT);
  pinMode (f, OUTPUT);
  pinMode (g, OUTPUT);
  pinMode (h, OUTPUT);  
  pinMode (bottone, INPUT);
}

void loop(){
  statoBottone=digitalRead(bottone);
  if(statoBottone==1){
    pulse=1-pulse;
    delay(1000);
    }
  if(pulse==1){
    for(i=j; i<=j+1; i+=1){
      numero(i);
      delay(periodo);
      j=i;
     }
   }
  else{
    for(i=j;i>=j-1; i-=1){
      numero(i);
      delay(periodo);
      j=i;
      }
    }
 }