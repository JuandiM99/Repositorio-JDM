/*
   DEBER 5.4: FUNCIONES ESPECÍFICAS
   Creación de semáfoto con RTOS
   NOMBRE: Juan Diego Martínez
*/

#include <FreeRTOSConfig.h>                // libreria  
#include <Arduino_FreeRTOS.h>              // libreria de RTOS.
const int ledVerde = 10;                   // define el pin del led verde.
const int ledAmarillo = 9;                 // define el pin del led amarillo.
const int ledRojo = 8;                     // define el pin del  led rojo.

#define configMAX_PRIORITIES 3;
typedef int TaskProfiler;            // se crea el objeto del gestor de tareas
TaskProfiler verdeLEDProfiler;       // definicion de tarea para led verde
TaskProfiler amaLEDProfiler;         // definicion de tarea para led amarilo
TaskProfiler rojoLEDProfiler;        // definicion de tarea para led rojo.
TaskHandle_t verde_Handle, amarillo_Handle, rojo_Handle;     // prioridad de las tareas para el semaforo
int cont = 0;                                                // contador

void setup() {
  //CREACION DE RUTINAS PARA CADA TAREA.
  xTaskCreate(verdeLEDControllerTask, "CIRCULAR", 100, NULL, 1, &verde_Handle);     // rutina para la tarea del red verde con sus parámetros
  xTaskCreate(amaLEDControllerTask, "PRECUACION", 100, NULL, 1, &amarillo_Handle);  // rutina para la tarea del amarillo verde con sus parámetros
  xTaskCreate(rojoLEDControllerTask, "ALTO", 100, NULL, 1, &rojo_Handle);           // rutina para la tarea del red rojo con sus parámetros
}

// METODOS POARA LAS RUTINAS

void verdeLEDControllerTask(void *pvParameters) {               // creacion del metodo para la primer tarea - led verde
  pinMode(ledVerde, OUTPUT);                                    // se define el modo del led verde
  while (1) {                                                   // ciclo para tarea del led verde
    verdeLEDProfiler++;                                         // aumento de la variable
    digitalWrite(ledVerde, digitalRead(ledVerde) ^ 1);          // escritura valor encendido o apagado
    vTaskDelay(1000);                                           // tiempo 
    cont++;
    if (cont == 10)                                             // condición a los 10 segundos de duracion de tarea
    { 
      vTaskSuspend(amarillo_Handle);                            // se suspende la tarea led amarillo
      vTaskSuspend(rojo_Handle);                                // se suspende la tarea led rojo
    }
  }
}

void amaLEDControllerTask(void *pvParameters) {                 // creacion del metodo para la segunda tarea - led amarrillo
  pinMode(ledAmarillo, OUTPUT);                                 // se define el modo del led amarrilo
  while (1) {                                                   // ciclo para tarea del led amarrillo
    amaLEDProfiler++;                                           // aumento de la variable
    digitalWrite(ledAmarillo, digitalRead(ledAmarillo) ^ 1);    // escritura valorr encendido o apagado
    vTaskDelay(500);                                            // tiempo 
    cont++;
    if (cont == 20)                                             // condicion a los 20 segundos de duracion de tarea
    { 
      vTaskSuspend(verde_Handle);                               // se suspende tarea del led verde
      vTaskSuspend(rojo_Handle);                                // se suspende tarea del led rojo
    }
  }
}

void rojoLEDControllerTask(void *pvParameters) {                // creacion del metodo para la tercera tarea - led rojo
  pinMode(ledRojo, OUTPUT);                                     // se define modo del led rojo
  while (1) {                                                   // ciclo para la tarea del led rojo
    rojoLEDProfiler++;                                          // aumento de la variable
    digitalWrite(ledRojo, digitalRead(ledRojo) ^ 1);            // escritura valorr encendido o apagado
    vTaskDelay(750);
    cont++;
    if (cont == 25)                                             // condición de tiempo a los 25 segundos
    { 
      vTaskSuspend(verde_Handle);                               // se suspende tarea del led verde
      vTaskSuspend(amarillo_Handle);                            // se suspende tarea del led rojo
      if (cont = 32)                                            // condicion de tiempo a los 32 segundos 
      {
        cont = 0;                                               // reinicio de contador 
      }
    }
  }
}
void loop() {
}
