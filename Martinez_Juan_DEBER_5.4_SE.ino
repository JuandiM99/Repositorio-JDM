/*
 * DEBER 5.4: FUNCIONES ESPECÍFICAS
 * Creación de funciones en RTOS
 * OBJETIVO: Realizar el funcionamiento de un semáforo basados en las funciones y tareas de RTOS.
 *NOMBRE: Juan Diego Martínez 
 */
 #include <FreeRTOSConfig.h>
 #include <Arduino_FreeRTOS.h>              // libreria de RTOS.
 const int verde = 10;                       // define el pin del led verde.
 const int amarillo = 9;                    // define el pin del led amarillo.
 const int rojo = 8;                        // define el pin del  led rojo.
 #define configMAX_PRIORITIES 3;
 typedef int TaskProfiler;            // se crea el objeto del gestor de tareas
 TaskProfiler verdeLEDProfiler;       // definicion de tarea para led verde
 TaskProfiler amarilloLEDProfiler;    // definicion de tarea para led amarilo
 TaskProfiler rojoLEDProfiler;        // definicion de tarea para led rojo.
 TaskHandle_t verde_Handle,amarillo_Handle,rojo_Handle;
 int cont=0;
 
void setup() {
  //CREACION DE RUTINAS PARA CADA TAREA.
  xTaskCreate(verdeLEDControllerTask,"CIRCULAR",100,NULL,1,&verde_Handle);          // rutina para la tarea del red verde con sus parámetros.
  xTaskCreate(amarilloLEDControllerTask,"PRECUACION",100,NULL,1,&amarillo_Handle);  // rutina para la tarea del amarillo verde con sus parámetros.
  xTaskCreate(rojoLEDControllerTask,"ALTO",100,NULL,1,&rojo_Handle);                // rutina para la tarea del red rojo con sus parámetros.
}

//Creacion de métodos para las rutinas.
void verdeLEDControllerTask(void *pvParameters){        // creacion del metodo para la primer tarea
  pinMode(verde,OUTPUT);                                // se define el modo del led verde
  while(1){                                             // ciclo para led verde
    verdeLEDProfiler++;                                 // aumento de la variable
    digitalWrite(verde,digitalRead(verde)^1);           // escritura valorr encendido o apagado.                                    
    vTaskDelay(1000);
    cont++; 
    if(cont==10){                                       // condición a los 10 segundos   
    vTaskSuspend(amarillo_Handle);                      // suspende tarea led amarillo
    vTaskSuspend(rojo_Handle);                          // suspende tarea led rojo
    }
  }
}

void amarilloLEDControllerTask(void *pvParameters){      // creacion del metodo para la segunda tarea
  pinMode(amarillo,OUTPUT);                              // se define el modo del led amarrilo
  while(1){                                              // ciclo para led amarrillo
    amarilloLEDProfiler++;                               // aumento de la variable
    digitalWrite(amarillo,digitalRead(amarillo)^1);      // escritura valorr encendido o apagado. 
    vTaskDelay(500);
    cont++; 
    if(cont==20){                                        // Condicion a los 20 segundos  
    vTaskSuspend(verde_Handle);                          // Suspendo tarea del led verde
    vTaskSuspend(rojo_Handle);                           // Suspendo tarea del led rojo
    }
  }
}

void rojoLEDControllerTask(void *pvParameters){          // creacion del metodo para la tercera tarea
  pinMode(rojo,OUTPUT);                                  // se define modo del led rojo
  while(1){                                              // ciclo para led rojo
    rojoLEDProfiler++;                                   // aumento de la variable 
    digitalWrite(rojo,digitalRead(rojo)^1);              // escritura valorr encendido o apagado. 
    vTaskDelay(750);                                     
    cont++; 
    if(cont==25){                                        // Condición de tiempo a los 25 segundos    
    vTaskSuspend(verde_Handle);                          // Suspende tarea del led verde
    vTaskSuspend(amarillo_Handle);                       // Suspende tarea del led rojo 
    if(cont=32){
    cont=0;
    }
    }        
  }
}
void loop() {
}
