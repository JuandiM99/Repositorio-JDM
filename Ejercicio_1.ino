/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FACULTAD DE INGENIERIA EN CIENCIAS APLICADAS
 * SISTEMAS EMBEBIDOS
 * STEVEN FLORES
 * 5to Nivel; 
 * EXAMEN BIMESTRAL : Ejercicio 1
 */
 
#include <LiquidCrystal.h>
#include <MsTimer2.h>
LiquidCrystal lcd (13,12,11,10,9,8);
int on = 0;
int cont;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  attachInterrupt(0,activacion,LOW);
  MsTimer2::set(1000,contador);
  MsTimer2::start();
  Serial.println("Ingrese el mensaje a codificar");
  
}

void loop() {
  
}
void activacion(){
  switch(on){
    case 0:
    Serial.println("Inicio del sistema, inserte mediante el potenciometro el valor a jugar");
    Serial.println("Una vez ingresado presione nuevamente para iniciar contador");
    on++;
    break;
    case 1:
    Serial.println("Contador iniciado");
    on++;
    break;
    case 2:
    Serial.println(" Contador Detenido");
    on=0;
    break;
    
  }
}
void contador(){
  if(on==1){
    cont=analogRead(0);
    cont=map(cont,0,1023,10,20);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ingrese Contador");
    lcd.setCursor(0,1);
    lcd.print(cont);
  }
  if(on==2){
    cont--;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Corriendo");
    lcd.setCursor(0,1);
    lcd.print(String("Contador: ")+String(cont));
    if(cont==0){
      on=0;
      Serial.println("Contador Finalizado");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Finalizado");
      lcd.setCursor(0,1);
      lcd.print("Presione");
    }
   Serial.println("Ingrese el mensaje a codificar");
  }
}
