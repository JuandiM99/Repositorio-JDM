/*
 * CAPITULO III: MÓDULOS DE COMUNICACIÓN  i2c
 * CÓDIGO DEBER 3.1 : Comunicación I2C configurar un Maestro y 3 esclavos
 * OBJETIVO: El usuario envia caracteres 
 * NOMBRE: Juan Diego Martínez
 */
/////////////ESCLAVO 2////////
#include <Wire.h>;    // libreria I2C
char dato;           // variable de almacenamiento
const int led4=8;     // led 4 en pin8
const int led5=9;     // led 5 en pin9
const int led6=10;    // led 6 en pin10

void setup() {
  Wire.begin(2);                  // id del esclavo
  Wire.onReceive(eventoEsc2);     // llama al evento creado
  Serial.begin(9600);             // inicia la comunicacino serial y velocidad
  pinMode(led4,OUTPUT);           // led 4 determina como salida
  pinMode(led5,OUTPUT);           // led 5 determina como salida
  pinMode(led6,OUTPUT);           // led 3 determina como salida
}

void loop() {
  // put your main code here, to run repeatedly:

}

void eventoEsc2 (int bytes){          // creacion del evento para el esclavo 2
  while(Wire.available())             // verifica la disponibilidad del registro
  {
    dato=Wire.read();                 // lee el dato ingresado para comprar las opciones determinadas
    if(dato=='Y')                     // compara el dato si pertenece a la opcion del esclavo 2
    {
      digitalWrite(led4,HIGH);        // se realiza el ecendido y apagado de los tres leds
      delay(7000);
      digitalWrite(led4,LOW);
      delay(7000);
      digitalWrite(led5,HIGH);
      delay(7000);
      digitalWrite(led5,LOW);
      delay(7000);
      digitalWrite(led6,HIGH);
      delay(7000);
      digitalWrite(led6,LOW);
      delay(7000);
    }
  }
}
