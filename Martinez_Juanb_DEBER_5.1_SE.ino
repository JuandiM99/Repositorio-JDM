/*
 * DEBER 5.1: Funciones Específicas - Memoria EEPROM
 * TEMA: memorias EEPROM
 * OBJETIVO: Realizar la escritura de la memoria EEPROM a travez de un teclado matricial, el cual debe cumplir que se visualice en 
 * una LCD cada caracter que se introduzca (uno por uno el que vayamos escribiendo en la memoria EEPROM), es decir, cada vez que se 
 * presione una tecla. Con una tecla en específico, la que usted decida, al presionarla, en la LCD se debe observar todos los caracteres 
 * que se guardaron en la memoria. Esto debe visualizarse de la posición menor a la posición mayor si se observa de derecha a izquierda en la LCD.
 * 
 * NOMBRE: Juan Diego Martinez          
 */
#include <LiquidCrystal.h>              // libreria para la LCd
#include <Keypad.h>                     // libreria para el teclado matricial
#include <EEPROM.h>                     // libreria para la memoria EEPROM
LiquidCrystal lcd {A0,A1,A2,A3,A4,A5};  // declaracion de los pines
const byte f=4;                         // numero de filas
const byte c=4;                         // numero de columnas
const int led=1;                        // variable de led 
char datos[16];
int tam=0;
char tecladoM [f][c] = {                // creación de matriz del teclado matricial 
  {'1','2','3','a'},
  {'4','5','6','b'},
  {'7','8','9','c'},
  {'*','0','#','d'}
  };
byte pinFilas[f] = {9,8,7,6};          // pines de conexion de filas Arduino-Teclado Matricial
byte pinColum [c] = {5,4,3,2};         // pines de conexion de columnas Arduino-Teclado Matricial
Keypad tecMat = Keypad(makeKeymap(tecladoM),pinFilas,pinColum,f,c);  // creacion de un objeto de acuerdo a la
int i=0;                    // variable para el contador
char teclaIng;              // variable para las letras del teclado

void setup() {
  lcd.begin(16,2);          // inicio de la LCD
  pinMode(led,OUTPUT);      // modo del led
}

void loop() {
    char teclaIng = tecMat.getKey();                // funcion del teclado matricial

    if(teclaIng != NO_KEY)                          // condicion de ningun caracter ingresado por teclado
    {
      digitalWrite(led,HIGH);                       // encendido de led cuando ingreso datos
      delay(500);                                   // tiempo de encendido
      lcd.setCursor(0,0);                           // posicion en la LCD
      lcd.println("Ud. INGRESO:"+String(teclaIng)); // muestro el dato ingresado a la LCD
      datos[tam]=teclaIng;                          // creacion de vector con los datos
      digitalWrite(led,LOW);                        // apago el led
      delay(100);                                     
      tam++;                                        // aumento de variable para el vector
    }

    if(teclaIng=='a')                               // condicion para mostrrar todos los datos
    {
      lcd.clear();                                  // limpio la LCD
      lcd.setCursor(0,0);                           // posicion de la LCD
      lcd.println("DATOS TOTALES");                 // mensaje 
      tam=tam-1;                                    // resta debido alcaracter del a 
      for(i=0;i<=tam;i++)                           // ciclo de recorrido
      {
        lcd.setCursor(0,1);                         // posicion del vector
        EEPROM.put(i,datos[i]);                     // guardo en la memoria EEPROM
        lcd.setCursor(i,1);                         // posicion de la LCD
        lcd.print(EEPROM.get(i,datos[i]));          // impresion de datos en la LCD
        delay(300);                                 
      }
    }

  
}
