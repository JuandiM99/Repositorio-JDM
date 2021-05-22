/*
 * DEBER 4.2: PEREFERICOS ESPCIALES 
 * OBJETIVO: Se va activar un juego de leds por medio de la interrupcion cero y la eleccion de numero de veces que querramos jugar 
 * se realizara con la otra interrupcion (uno) MODIFICIAR EL EJERCICIO EN CLASE 
 * NOMBRE: Juan Diego Martínez
 */
const int leds[6]={13,12,11,10,9,8};    // vector de leds del juego
  int on;                               // contador de la interrupcion 0
  int cont;                             // contador para los leds
  int i;                                // Variable de conteo
  int j=0;                              // Variable de conteo
void setup() {
  for(i=0;i<6;i++)                      // delcaracion del modo de los leds
  {
    pinMode(leds[i], OUTPUT);           // leds de salida
  }
  i=0;
  Serial.begin(9600);                   // inicio de la comunicacion serial
  attachInterrupt(0,activacion,LOW);    // creacion de la interrupcion de activacion
  attachInterrupt(1,contador,LOW);      // creacion de la interrupcion de contador encendido de los leds
  Serial.println("PRESIONE INICIAR ");
}

void loop() {       
  if(on==2)                           // condicional para encendido de leds
  {
    for(;i<cont;i++)                  // ciclo para el encendido de los ldes
    {
      for(j=0;j<6;j++)                //Recorrido para los leds 
      {
        digitalWrite(leds[j],HIGH);   // encendido de leds
        delay(200);                   
        digitalWrite(leds[j],LOW);    // apagado de leds
        delay(200);                   
      }
    }
  }
}
void activacion(){                                // creacion de metodo de activacion 
  switch(on)                            
  {
    case 0:                                       // caso de inicio
    Serial.println("Inicio del Sistema: ");
    Serial.println("Ingrese el numero de veces que desee jugar");
    on++;
    break;                             
    case 1:                                       // caso para contador de encendido de leds
    Serial.println("Inicio de Juego");            
    on++;
    break;
    case 2:                                       // caso de fin del juego
    Serial.println("Juego finalizado");
    cont=0;                                       // reinicio de variables
    on=0;
    i=0;
    break;
  }
}
void contador(){                                  // metodo de recolecion e impresion del encendido de leds  
  if(on==1)
  {
    cont++;                                       // contador de veces a jugar
    Serial.println(String("Juega ")+String(cont)+String(" veces")); // empresion de mensaje y variables
  }
}
