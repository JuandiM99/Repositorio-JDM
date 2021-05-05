/*
 * CAPITULO II : PUERTOS COFIGURADOS 
 * CODIGO I: Manejo de puertos configurados como saluidas 
 * OBJETIVO: Encender y apagar leds mediante el uso de diferentes tipos de variables 
 * AUTOR: Juan Diego Martinez
 */

//Varibales: numericas, enteras (int), decimales (float), caracteres (chart)

#define led1 8         // uso de #define, es una variable que no se puede alterar su error y no vindra un error 
int led2 = 9 ;         // se puede consiedar como una variable normal 
const int led3 = 10;   // variable constante 

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);  // delcaro el pin 8 como salida 
  pinMode(led2, OUTPUT); // delcaro el pin 9 como salida
  pinMode(led3, OUTPUT); // delcaro el pin 10 como salida
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1, HIGH); // envio 5V al pin8
  delay(500);               // se detiene el microcontrolador por medio segundo
  digitalWrite(led1,LOW) ;  // envia 0V al pin 8  
  delay(500);               // se detiene el microcontrolador por medio segundo

  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  delay(400);
  
  digitalWrite(led3, HIGH);
  digitalWrite(led2, LOW);
  delay(400);
}
