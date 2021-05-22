/*
 * DEBER 4.3: RELOJ Y PANTALLA LCD 20X4
 * OBJETIVO; Reloj de timer 2 Y PANTALLA LCD 20X4
 * NOMBRE: Juan Diego Martínez 
 */
#include <MsTimer2.h>             // libreria Timer 2
#include <LiquidCrystal.h>        // libreria LCD
LiquidCrystal lcd{13, 12, 11, 10, 9, 8};     // objeto de la libreria LCD
int segundos=0;                              // variable de segundos
int minutos=0;                               // variable de minutos
int horas=0;                                 // variable de horas

void setup() {
  lcd.begin(20,4);                // inicio de la LCD 20x4
  MsTimer2::set(1000,reloj);      // configura el timer 
   MsTimer2::start();             // inicia el Timer 2
}

void loop() {
}

void reloj()
{
  if(segundos<59)                         //Condicion de segundos
  {
    segundos++;                           //Incremento de variable
  }else{
    segundos=0;
    if(minutos<59)                        //Condicion de minutos
    {
      minutos++;                          //Incremento de variable
    }else{
      minutos=0;
      if(horas<23)                        //Condicion de horas
      {
        horas++;                          //Incremento de variable            
      }else{
        horas=0;
      }
    }
  }   
  lcd.clear();                    
  //ENCABEZADO
  lcd.setCursor(0,0);                    // posicion de la LCD
  lcd.print("-----BIENVENIDOS-----");    // impresion de mesaje
  lcd.setCursor(0,1);                    // posicion de la LCD
  lcd.print("JUAN DIEGO MARTINEZ");      // impresion de mesaje
  lcd.setCursor(0,2);                    // posicion de la LCD
  lcd.print("Horas:Minutos:Segundo");    // impresion de mesaje
  // IMPRESION DE DATOS
  lcd.setCursor(6,3);                    // posicion de la LCD.
  lcd.print(String(horas)+String(":"));  // impresion de mesaje
  lcd.setCursor(8,3);                    // posicion de la LCD
  lcd.print(String(minutos)+String(":"));// impresion de mesaje
  lcd.setCursor(10,3);                   // posicion de la LCD
  lcd.print(String(segundos));           // impresion de mesaje
}
