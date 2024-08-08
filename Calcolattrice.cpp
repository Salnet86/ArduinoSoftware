#includere

#includere

#includere

//definizioni della tastiera

byte const RIGHE = 4;

byte const COLS = 4;

chiavi carattere[RIGHE][COLS] = {

  {'1', '2', '3', '+'},

  {'4', '5', '6', '-'},

  {'7', '8', '9', '*'},

  {'C', '0', '=', '/'}

};

byte rowPins[RIGHE] = {0, 1, 2, 3};

byte colpins [cols] = {4, 5, 6, 7};

 

Tastiera ourKeypad = Tastiera(makeKeymap(chiavi), rowPins, colPins, ROWS, COLS);

// inizializza lcd

LiquidCrystal_I2C LCD (0x3f, 20,4);

 

// dì qui quali sono questi valori

booleano firstNumState = vero;

Stringa numero primo = “”;

Stringa secondoNum = “”;

risposta mobile = 0.0;

addetto = ' ';

 

void setup () {

  //qui accendiamo lo schermo

  LCD.Inizio (16,2);

  lcd.init ();

  lcd.init ();

  lcd.retroilluminazione();

  lcd.setCursor(0,0);

  lcd.print("Elettronica");

  lcd.setCursor(0,1);

  lcd.print("Per te");

  ritardo (1500);

  LCD.Cancella ();

  lcd.setCursor(0,0);

  lcd.print("calcolatrice");

  ritardo (1500);

  LCD.Cancella ();

}

void loop () {

  Char Newkey = Ourkeypad.getKey ();

  //cosa fare quando riceve un numero

  if(nuovaChiave != NO_KEY && (nuovaChiave == '1' || nuovaChiave == '2' || nuovaChiave == '3' || nuovaChiave == '4' || nuovaChiave == '5' || nuovaChiave = = '6' || nuovaChiave == '7' || nuovaChiave == '8' || nuovaChiave == '9' || nuovaChiave =='0′)){

    if(firstNumState == vero){

      firstNum = firstNum + newKey;

      lcd.print (nuova chiave);

    Else {}

      secondNum = secondNum + nuovaChiave;

      lcd.print (nuova chiave);

    }

  }

  //cosa fare quando riceve un operatore

  if(nuovaChiave != NO_KEY && (nuovaChiave == '+' || nuovaChiave == '-' || nuovaChiave == '*' || nuovaChiave == '/')) {

    if(firstNumState == vero){

      opera = nuova chiave;

      firstNumState = falso;

      lcd.print(operativo);

    }

  }

  //qui diciamo cosa succede quando tu

  //stampa #

  if(newKey != NO_KEY && newKey == '='){

    //cosa fare come operatore

    //+ è

    se(operativo == '+'){

      risposta = firstNum.toFloat() + secondNum.toFloat();

    }

    //cosa fare come operatore

    //- è

    se(operativo == '-'){

      risposta = firstNum.toFloat() - secondNum.toFloat();

    }

    //cosa fare come operatore

    //* è

    se(operativo == '*'){

      risposta = firstNum.toFloat() * secondNum.toFloat();

    }

    //cosa fare come operatore

    //diviso per è

    se(operativo == '/'){

      risposta = firstNum.toFloat() / secondNum.toFloat();

    }

    lcd.setCursor(0,0);

    lcd.print(firstNum);

    lcd.print(operativo);

    lcd.print(secondNum);

    lcd.setCursor(0,1);

    lcd.print ("=");

    lcd.print(risposta);

    firstNumState = vero;

  }

  if(newKey != NO_KEY && newKey == 'C'){

    //qui diciamo cosa succede quando tu

    //stampa *

    LCD.Cancella ();

    lcd.setCursor(0,0);

    firstNum = “”;

    secondoNum = “”;

    risposta = 0;

    opera = ' ';

  }

}