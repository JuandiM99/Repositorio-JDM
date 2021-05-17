/*
 * CAPITULO III: MÓDULOS DE COMUNICACIÓN  i2c
 * CÓDIGO DEBER 3.1 : Comunicación I2C configurar un Maestro y 3 esclavos
 * OBJETIVO: El usuario envia caracteres 
 * NOMBRE: Juan Diego Martínez
 */
/////////////ESCLAVO 1////////
#include <Wire.h>;    // libreria I2C
char dato;           // variable de almacenamiento
const int led1=8;     // led 1 en pin8
const int led2=9;     // led 2 en pin9
const int led3=10;    // led 3 en pin10

void setup() {
  Wire.begin(2);                  // id del esclavo
  Wire.onReceive(eventoEsc1);     // llama al evento creado
  Serial.begin(9600);             // inicia la comunicacino serial y velocidad
  pinMode(led1,OUTPUT);           // led 1 determina como salida
  pinMode(led2,OUTPUT);           // led 2 determina como salida  
  pinMode(led3,OUTPUT);           // led 3 determina como salida
}

void loop() {
  // put your main code here, to run repeatedly:

}

void eventoEsc1 (int bytes){          // creacion del evento para el esclavo 1 
  while(Wire.available())             // verifica la disponibilidad del registro
  {
    dato=Wire.read();                 // lee el dato ingresado para comprar las opciones determinadas
    if(dato=='X')                     // compara el dato si pertenece a la opcion del esclavo 1
    {
      digitalWrite(led1,HIGH);        // se realiza el ecendido y apagado de los tres leds
      delay(7000);
      digitalWrite(led1,LOW);
      delay(7000);
      digitalWrite(led2,HIGH);
      delay(7000);
      digitalWrite(led2,LOW);
      delay(7000);
      digitalWrite(led3,HIGH);
      delay(7000);
      digitalWrite(led3,LOW);
      delay(7000);
    }
  }
}
