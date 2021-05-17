/*
 * CAPITULO III: MÓDULOS DE COMUNICACIÓN  i2c
 * CÓDIGO DEBER 3.1 : Comunicación I2C configurar un Maestro y 3 esclavos
 * OBJETIVO: El usuario envia caracteres 
 * NOMBRE: Juan Diego Martínez
 */
/////////////ESCLAVO 3////////
#include <Wire.h>;    // libreria I2C
char dato;           // variable de almacenamiento
const int led7=8;     // led 7 en pin8
const int led8=9;     // led 8 en pin9
const int led9=10;    // led 9 en pin10

void setup() {
  Wire.begin(2);                // id del esclavo
  Wire.onReceive(eventoEsc3);   // llama al evento creado
  Serial.begin(9600);           // inicia la comunicacino serial y velocidad
  pinMode(led7,OUTPUT);         // led 7 determina como salida
  pinMode(led8,OUTPUT);         // led 8 determina como salida  
  pinMode(led9,OUTPUT);         // led 9 determina como salida
}

void loop() {
  // put your main code here, to run repeatedly:

}

void eventoEsc3 (int bytes){        // creacion del evento para el esclavo 3
  while(Wire.available())           // verifica la disponibilidad del registro
  {
    dato=Wire.read();               // lee el dato ingresado para comprar las opciones determinadas
    if(dato=='Z')                   // compara el dato si pertenece a la opcion del esclavo 3
    {
      digitalWrite(led7,HIGH);      // se realiza el ecendido y apagado de los tres leds
      delay(7000);
      digitalWrite(led7,LOW);
      delay(7000);
      digitalWrite(led8,HIGH);
      delay(7000);
      digitalWrite(led8,LOW);
      delay(7000);
      digitalWrite(led9,HIGH);
      delay(7000);
      digitalWrite(led9,LOW);
      delay(7000);
    }
  }
}
