#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
  // lcd.init(); // Inicializa LCD
  // lcd.backlight(); // Liga luz do LCD
  // lcd.clear();
  // lcd.print("Joao Pedro");// Esceve no LCD
  // lcd.setCursor(0, 1);

const int col1 = 8;
const int col2 = 9;
const int col3 = 10;
const int col4 = 11;
const int col5 = 12;
const int col6 = 13;

const int row1 = 1;
const int row2 = 2;
const int row3 = 3;
const int row4 = 4;

boolean state_11 = true;boolean state_12 = true;boolean state_13 = true;boolean state_14 = true;boolean state_15 = true;boolean state_16 = true;boolean state_21 = true;boolean state_22 = true;boolean state_23 = true;boolean state_24 = true;boolean state_25 = true;boolean state_26 = true;boolean state_31 = true;boolean state_32 = true;boolean state_33 = true;boolean state_34 = true;boolean state_35 = true;boolean state_36 = true;boolean state_41 = true;boolean state_42 = true;boolean state_43 = true;boolean state_44 = true;boolean state_45 = true;boolean state_46 = true;
int tamanho = 10;
String comandos[10];
float input[10];
int operador = 0;
float teste = 13.33;

void printt(int op){
   Serial.println(input[op]);
}

float digito(int tecla,float inp[10],int op){
  float guarda = 10*inp[op] + float(tecla);
  return guarda;
}


void resul(float input[10],String comandos[10],int operador){
  float resultado = 0.0;
  for (int i = 0; i <= operador; i++) {
    if (comandos[i] == "sum"){
    resultado += input[i] ;
    }
    else if (comandos[i] == "times"){
    resultado *= input[i] ;
    }
    else if (comandos[i] == "div"){
    resultado /= input[i] ;
    }
    else if (comandos[i] == "minus"){
    resultado -= input[i] ;
    }    }
  Serial.println('O resultado eh:');
  Serial.println(resultado);
}

void setup() {
  Serial.begin(9600);
  lcd.init(); // Inicializa LCD
  lcd.backlight(); // Liga luz do LCD

  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);
  
  pinMode(col1, INPUT);
  pinMode(col2, INPUT);
  pinMode(col3, INPUT);
  pinMode(col4, INPUT);
  pinMode(col5, INPUT);
  pinMode(col6, INPUT);
}

void loop()
{
  digitalWrite(row1, HIGH);
  digitalWrite(row2, LOW) ;
  digitalWrite(row3, LOW) ;
  digitalWrite(row4, LOW) ;
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col1) && state_11){
    state_11 = false;
    printt(operador);
  }
  else if (digitalRead(col1) == false){state_11 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col2) && state_12){
    state_12 = false;
  }
  else if (digitalRead(col2) == false){state_12 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col3) && state_13){
    state_13 = false;
    input[operador] = digito(1,input,operador);
  }
  else if (digitalRead(col3) == false){state_13 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col4) && state_14){
    state_14 = false;
    input[operador] = digito(4,input,operador);
  }
  else if (digitalRead(col4) == false){state_14 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col5) && state_15){
    state_15 = false;
    input[operador] = digito(7,input,operador);
  }
  else if (digitalRead(col5) == false){state_15 = true;}
////////////////////////////////////////////////////////////////////////////// 
  if (digitalRead(col6) && state_16){
    state_16 = false;
    input[operador] = digito(0,input,operador);
  }
  else if (digitalRead(col6) == false){state_16 = true;}
//////////////////////////////////////////////////////////////////////////////
  digitalWrite(row1, LOW);
  digitalWrite(row2, HIGH);
  digitalWrite(row3, LOW) ;
  digitalWrite(row4, LOW) ;
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col1) && state_21){
    state_21 = false;
    printt(operador);
  }
  else if (digitalRead(col1) == false){state_21 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col2) && state_22){
    state_22 = false;
    printt(operador);
  }
  else if (digitalRead(col2) == false){state_22 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col3) && state_23){
    state_23 = false;
    input[operador] = digito(2,input,operador);
  }
  else if (digitalRead(col3) == false){state_23 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col4) && state_24){
    state_24 = false;
    input[operador]= digito(5,input,operador);
  }
  else if (digitalRead(col4) == false){state_24 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col5) && state_25){
    state_25 = false;
    input[operador]= digito(8,input,operador);
  }
  else if (digitalRead(col5) == false){state_25 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col6) && state_26){
    state_26 = false;
    printt(operador);
  }
  else if (digitalRead(col6) == false){state_26 = true;}
//////////////////////////////////////////////////////////////////////////////  
  digitalWrite(row1, LOW);
  digitalWrite(row2, LOW) ;
  digitalWrite(row3, HIGH) ;
  digitalWrite(row4, LOW) ;
 ////////////////////////////////////////////////////////////////////////////// 
  if (digitalRead(col1) && state_31){
    state_31 = false;
    printt(operador);
  }
  else if (digitalRead(col1) == false){state_31 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col2) && state_32){
    state_32 = false;
    comandos[operador] = "minus";
    operador ++;
    // printt(operador);
  }
  else if (digitalRead(col2) == false){state_32 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col3) && state_33){
    state_33 = false;
    input[operador]= digito(3,input,operador);
  }
  else if (digitalRead(col3) == false){state_33 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col4) && state_34){
    state_34 = false;
    input[operador]= digito(6,input,operador);
  }
  else if (digitalRead(col4) == false){state_34 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col5) && state_35){
    state_35 = false;
    input[operador]= digito(9,input,operador);
  }
  else if (digitalRead(col5) == false){state_35 = true;}
////////////////////////////////////////////////////////////////////////////// 
  if (digitalRead(col6) && state_36){
    state_36 = false;
    printt(operador);
  }
  else if (digitalRead(col6) == false){state_36 = true;}
//////////////////////////////////////////////////////////////////////////////
  digitalWrite(row1, LOW);
  digitalWrite(row2, LOW) ;
  digitalWrite(row3, LOW) ;
  digitalWrite(row4, HIGH) ;
//////////////////////////////////////////////////////////////////////////////  
  if (digitalRead(col1) && state_41){
    state_41 = false;
    printt(operador);
  }
  else if (digitalRead(col1) == false){state_41 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col2) && state_42){
    state_42 = false;
    comandos[operador] = "div";
    operador ++;
    // printt(operador);
  }
  else if (digitalRead(col2) == false){state_42 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col3) && state_43){
    state_43 = false;
    comandos[operador] = "times";
    operador ++;
    // printt(operador);
  }
  else if (digitalRead(col3) == false){state_43 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col4) && state_44){
    state_44 = false;
    comandos[operador] = "sum";
    operador ++;
    // printt(operador);
  }
  else if (digitalRead(col4) == false){state_44 = true;}
//////////////////////////////////////////////////////////////////////////////
  if (digitalRead(col5) && state_45){
    state_45 = false;
    resul(input,comandos,operador);
  }
  else if (digitalRead(col5) == false){state_45 = true;}
//////////////////////////////////////////////////////////////////////////////
  // if (digitalRead(col6) && state_46){
  //   state_46 = false;
  //   printt(operador);
  // }
  // else if (digitalRead(col6) == false){state_46 = true;}
//////////////////////////////////////////////////////////////////////////////
  
}