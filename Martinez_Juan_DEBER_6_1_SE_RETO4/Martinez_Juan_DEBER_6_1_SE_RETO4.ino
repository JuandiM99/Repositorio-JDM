/*
 * Sistemas embebidos
 * Deber 6.1: Reto 4
 * Nombre: Juan Diego Martínez
 */
const int led=7;
void setup() {
  Serial.begin(9600);                 // inicio de comunicacion serial
  pinMode(led,OUTPUT);                // declarar pin 7 como salida
}

void loop() {
  if(Serial.available())              // verificar si existen datos en la comunicaciñon serial
  {
    char dato=Serial.read();          // lectura de dato y alaceno en variable de tipo char
    if(dato=='e')                     // condición de encendido
    {
      digitalWrite(led,1);            // encendido de led
    }
    else
    {
      if(dato=='a')                   // condición para apagar el led
      {
        digitalWrite(led,0);          // apagado del led
      }
    }
  }
}
