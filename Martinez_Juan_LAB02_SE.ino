/*
 * LABORATORIO II: COMUNICACI ON - CAD - INTERRUPCIONES
* CODIGO II
* OBJETIVO: Realizar un sistema domótico de un reloj horero-minutero observado en una LCD añadiendo dos interrupciones la primera sera de encendido-apagado- y el otro el modo de funcionamiento.
* NOMBRE: Juan Diego Martínez
* FUNCIONES:
  *          LiquidCrystal.h     
*          print(mensaje)  Envío Mensajes
*          setCursor(col,fil)       
*          attachinterrupt(interrupt,rutina.modo)
*/
#include <LiquidCrystal.h>
#include <MsTimer2.h>
LiquidCrystal lcd {13,12,11,10,9,8};    // declaracion de pines lcd
const int leds[4]={7,6,5,4};            // pines de los leds
const int sensor1=A2;                   // declaraciones de los pines para los sensores 
const int sensor2=A3;
const int sensor3=A4;
const int sensor4=A5;
int minutos=0;       // variable de minutos
int horas=0;         // variable de HORAS
int on=0;            // variable del sistema para opciones
int on2=0;           // variable del sistema para opciones
int i;               // variables para ciclos
int random1;         // variable para leds randomicos
int horaP;           // variable cambio de hora
int minutosP;        // variable cambio de minutos
void setup() {
  for(i=0;i<4;i++)            // ciclo for para leds
  {
    pinMode(leds[i],OUTPUT);  // declaro modo de los leds
  }
  pinMode(sensor1,INPUT);     // declaracion del modo de los sensores
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
  i=0;
  Serial.begin(9600);                   // inicio de la comunicacion serial
  lcd.begin(16,2);                      // inicio de la LCD
  attachInterrupt(0,iniciador,LOW);     // interrupciones 1
  attachInterrupt(1,seleccionador,LOW); // interrupciones 2
  MsTimer2::set(1000,reloj);            // configura el timer 2 a 1 segundos
  Serial.println("Presione para encender el sistema");  
}

void loop() {
  if(on==2)         // AQUI SE REALIZA UN LLAMADO A LOS METODOS PARA CADA UNO DE LOS MODOS ASIGNADOS
  {
    switch(on2)
    {
      case 1:
      modo1();
      break;
      case 2: 
      modo2();
      break;
      case 3:
      modo3();
      break;
    }
  }
}

void iniciador (){            // creacion de metodo de inicializacion
  switch (on)                 // switch para cada uno de los casos
  {
    case 0:
    MsTimer2::start();        // inicio del reloj
    Serial.println("SELECCIONE EL MODO QUE DESEA REALIZAR )");
    on++;
    break;
    case 1:
    Serial.println("EJECUTANDO EL MODO");
    on++;
    break;
    case 2:
    Serial.println("FIN DEL SISTEMA DOMOTICO");
    on=0;               // reinicio las variables
    on2=0;
    lcd.clear();        // limpio la LCD
    MsTimer2::stop();   // paro el reloj
  }
}

void seleccionador (){        //creacion del segundo metodo 
  if(on==1)
  {
    switch(on2)               // switch para cada uno de los casos    
    {
      case 0:
      Serial.println("Activacion de leds de forma aleatoria");
      on2++;
      break;
      case 1:
      Serial.println("Cambio de la hora del reloj");
      on2++;
      break;
      case 2:
      Serial.println("Sistema de seguridad de sensores");
      on2++;
      break;
      case 3:
      Serial.println("Selccion de modos");
      on2=0;        // reinicio variable
      break;
    }
  }
  if(on==2)
  {
    on=0;       // reinicio variable
    on2=0;      // reinicio variable
    Serial.println("Salio de la ejecucion del modo");   // mensaje de salida 
  }
}

// MODO UNO
void modo1 (){
  for(i=0;i<5;i++)
  {
     random1=random(1,5);               // selecciona un valor randomico para el led
     digitalWrite(leds[random1],HIGH);  // encendido y apagado del led a 1000 milisegundos
     delay(1000);
     digitalWrite(leds[random1],LOW);
     delay(1000);
  } 
  i=0;      // reinicio de variables
  on=0;
  on2=0; 
}

// MODO DOS
void modo2 (){
  horaP=analogRead(0);                // lectura el en pin A0
  horas=map(horaP,0,1023,0,23);       // operacion para transformar la Hora segun el numero de bits y sus valores maximos y minimos
  minutosP=analogRead(1);             // lectura el en pin A1
  minutos=map(minutosP,0,1023,0,59);  // operacion para transformar minutos segun el numero de bits y sus valores maximos y minimos
}

// MODO 3
void modo3(){
  if(digitalRead(sensor1)==LOW||digitalRead(sensor2)==LOW||digitalRead(sensor3)==LOW||digitalRead(sensor4)==LOW){   // condicional para los sensores sin son encendidos con el pulsador
    Serial.println("Un sensor ha sido activado, verifique la seguridad");
    delay(200);
  }
}

// CREACION DEL METODO DE RELOJ
void reloj(){         
    if(minutos<59)                        //Condicion de minutos
    {
      minutos++;                          //Incremento de variable
    }else
    {
      minutos=0;                          // reinicio de variable
      if(horas<23)                        //Condicion de horas
      {
        horas++;                          //Incremento de variable            
      }else
      {
        horas=0;                          // reinicio de variable
      }
    }
    
lcd.clear();            // AQUI SE SELECCIONA LA POSICION EN LA LCD Y EL ENVIO DE LA IMPRESION DE TEXTO Y VARIABLES
lcd.setCursor(0,0);
lcd.print("HORAS");
lcd.setCursor(5,1);
lcd.print(":");
lcd.setCursor(7,0);
lcd.print("MIN.");
lcd.setCursor(1,1);
lcd.print(horas);
lcd.setCursor(7,1);
lcd.print(minutos);

}
