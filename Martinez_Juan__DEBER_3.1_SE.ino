/*
 * CAPITULO III: MÓDULOS DE COMUNICACIÓN  i2c
 * CÓDIGO DEBER 3.1 : Comunicación I2C configurar un Maestro y 3 esclavos
 * OBJETIVO: El usuario envia caracteres 
 * NOMBRE: Juan Diego Martínez
 */
/////////////MASTER////////
#include <Wire.h>;                  // libreria I2C
char dato;                          // variable de almacenamiento de datos

void setup() {
  char dato;            // variable de datos
  Wire.begin();         // inicia la transmision I2C
  Serial.begin(9600);   // Inicia la comunicación serial
  Serial.println("DEBER 3.1 - JUAN DIEGO MARTINEZ "); // mensaje de inicio 
  Serial.println("Activacion Esclavo  UNO = X ");     // opcion para esclavo 1
  Serial.println("Activacion Esclavo  DOS = Y ");     // opcion para esclavo 2
  Serial.println("Activacion Esclavo  TRES = Z ");    // opcion para esclavo 3
}

void loop() {
  if(Serial.available()>0)            // Condicion de bytes disponible
  {
    
    dato=Serial.read();             // lee el dato de la variaable
    Wire.beginTransmission(2);      // empiza la comunicacion I2C
    Wire.write(dato);               // envio de datos
    Wire.endTransmission();         // termina la comunicacin serial
  }

}
