/*
 * CAPITULO II : PUERTOS COFIGURADOS 
 * DEBER - CODIGO II: Manejo de puertos configurados como salidas 
 * OBJETIVO: Encender y apagar 4 leds de forma simultanea mediante el uso de diferentes tipos de variables 
 * AUTOR: Juan Diego Martinez
 */
int led1 = 8 ; 
int led2 = 9 ;
int led3 = 10; 
int led4 = 11; 
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT); // delcaro el pin 8 como salida 
  pinMode(led2,OUTPUT); // delcaro el pin 9 como salida 
  pinMode(led3,OUTPUT); // delcaro el pin 10 como salida 
  pinMode(led4,OUTPUT); // delcaro el pin 11 como salida 
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1,HIGH); // envio 5V al pin8
  delay(500);              // se detiene el microcontrolador por medio segundo
  digitalWrite(led1,LOW);  // envio 0V al pin8
  delay(500);              // se detiene el microcontrolador por medio segundo


  digitalWrite(led2,HIGH);
  delay(500); 
  digitalWrite(led2,LOW);  
  delay(500);             

  digitalWrite(led3,HIGH);
  delay(500);
  digitalWrite(led3,LOW);
  delay(500);

  digitalWrite(led4,HIGH);
  delay(500);
  digitalWrite(led4,LOW);
  delay(500);
  
}
