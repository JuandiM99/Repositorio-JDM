/*
 * CAPITULO IV: PERIFERICOS ESPECIALES
 * DEBER 4.1 : DAD Y PWM
 * OBJETIVO: Realizar lecturas de conversor analogo digital para determinar la velocidad de dos motor en DC, mediante una LCD para cada motor.
 * NOMBRE: Juan Diego Martinez
 *            
 * 
 */
#include <LiquidCrystal.h>
const int btn1=A4;                      // creacion del boton
LiquidCrystal lcd1(13,12,5,4,3,2);      //Seleccion de pines para LCD.
int conversor1;                         //Variable para adquirir datos del conversor entre 0-1023.
float voltaje1;                         //Variable de conversion de conversor a voltaje.
int  dutty1;

const int sw=A5;                        // creacion del boton
LiquidCrystal lcd2(A2,A3,9,8,7,6);      //Seleccion de pines para LCD.
int conversor2;                         //Variable para adquirir datos del conversor entre 0-1023.
float voltaje2;                         //Variable de conversion de conversor a voltaje.
int  dutty2;
 
void setup() {
  lcd1.begin(16,2);                      //Inicializa la LCD.
  lcd2.begin(16,2);                      //Inicializa la LCD.
  pinMode(btn1,INPUT);                   // define al boton como entrada
  pinMode(sw,INPUT);

}

void loop() {
  if(digitalRead(btn1)==LOW)
  {
      conversor1=analogRead(A0);              //Lectura del canal A0-0-14
      voltaje1=(conversor1*5.0)/1023.0;       //Conversor de voltaje.
      dutty1=conversor1/4;                    //Cambio la escala para el dutty cicle.
      analogWrite(11,dutty1);                 //Envio de valor al pin 11.
      lcd1.setCursor(0,0);                    // posicin del cursor en la LCD
      lcd1.print("CAD: " );                   // mensaje de salida
      lcd1.setCursor(5,0);                    // posicin del cursor en la LCD
      lcd1.print(conversor1);                 // muestra el resultado del conversor
      lcd1.setCursor(0,1);                    // posicin del cursor en la LCD
      lcd1.print("V: ");                      // mensaje de salida
      lcd1.setCursor(3,1);                    // posicin del cursor en la LCD
      lcd1.print(voltaje1);                   // muestra el resultado del voltaje
      lcd1.setCursor(9,1);                    // posicin del cursor en la LCD
      lcd1.print("PWM: ");                    // mensaje de salida
      lcd1.setCursor(13,1);                   // posicin del cursor en la LCD
      lcd1.print((dutty1*100)/255);           // realiza la regla de tres
      delay(300);
      lcd1.clear();                           // limpia pantalla
  }else{
    lcd1.clear();
  }

  // otro
  if(digitalRead(sw)==HIGH)
  {
      conversor2=analogRead(A1);              //Lectura del canal A0-0-14
      voltaje2=(conversor2*5.0)/1023.0;       //Conversor de voltaje.
      dutty2=conversor2/4;                    //Cambio la escala para el dutty cicle.
      analogWrite(10,dutty2);                 //Envio de valor al pin 11.
      lcd2.setCursor(0,0);                    // posicin del cursor en la LCD
      lcd2.print("CAD: " );                   // mensaje de salida
      lcd2.setCursor(5,0);                    // posicion del cursor en la LCD
      lcd2.print(conversor2);                 // muestra el resultado del conversor
      lcd2.setCursor(0,1);                    // posicion del cursor en la LCD
      lcd2.print("V: ");                      // mensaje de salida
      lcd2.setCursor(3,1);                    // posicion del cursor en la LCD
      lcd2.print(voltaje2);                   // muestra el resultado del voltaje
      lcd2.setCursor(9,1);                    // posicion del cursor en la LCD
      lcd2.print("PWM: ");                    // mensaje de salida
      lcd2.setCursor(13,1);                   // posicion del cursor en la LCD
      lcd2.print((dutty2*100)/255);           // realiza la regla de tres
      delay(300);                             
      lcd2.clear();                           // limpia pantalla
  }
}
