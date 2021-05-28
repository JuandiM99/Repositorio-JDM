/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FACULTAD DE INGENIERIA EN CIENCIAS APLICADAS
 * SISTEMAS EMBEBIDOS
 * STEVEN FLORES
 * 5to Nivel; 
 * EXAMEN BIMESTRAL : Ejercicio 2
 */
#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);
String dato;
int tam;
int tam1;
int i=0;
String salida;
int j=0;
int k=0;

void setup(){
  Serial.begin(9600);
  Serial.println("Ingrese el mensaje a codificar");
}
void loop(){
  if(Serial.available()>0){
    dato=Serial.readString(); //lee el dato 
    dato.toLowerCase(); // convertimos a minusculas
    tam = dato.length()+1; //tener la cadena sin errores
    char vector[tam];     //creo el vector
    dato.toCharArray(vector,tam);
    for(i=0;i<tam-1;i++){
         switch(vector[i]){
            case 'a':
            salida=salida+" *-";  //codificación
            break;
            case 'b':
            salida=salida+" -***";
            break;
            case 'c':
            salida=salida+" -*-*";
            break;
            case 'd':
            salida=salida+" -**";
            break;
            case 'e':
            salida=salida+" *";
            break;
            case 'f':
            salida=salida+" **-*";
            break;
            case 'g':
            salida=salida+" --*";
            break;
            case 'h':
            salida=salida+" ****";
            break;
            case 'i':
            salida=salida+" **";
            break;
            case 'j':
            salida=salida+" *---";
            break;
            case 'k':
            salida=salida+" -*-";
            break;
            case 'l':
            salida=salida+" *-**";
            break;
            case 'm':
            salida=salida+" --";
            break;
            case 'n':
            salida=salida+" -*";
            break;
            case 'o':
            salida=salida+" ---";
            break;
            case 'p':
            salida=salida+" *--*";
            break;
            case 'q':
            salida=salida+" --*-";
            break;
            case 'r':
            salida=salida+" *-*";
            break;
            case 's':
            salida=salida+" ***";
            break;
            case 't':
            salida=salida+" -";
            break;
            case 'u':
            salida=salida+" **-";
            break;
            case 'v':
            salida=salida+" **-";
            break;
            case 'w':
            salida=salida+" *--";
            break;
            case 'x':
            salida=salida+" -**-";
            break;
            case 'y':
            salida=salida+" -*--";
            break;
            case 'z':
            salida=salida+" --**";
            break;
            case '1':
            salida=salida+" *----";
            break;
            case '2':
            salida=salida+" **---";
            break;
            case '3':
            salida=salida+" ***--";
            break;
            case '4':
            salida=salida+" ****-";
            break;
            case '5':
            salida=salida+" *****";
            break;
            case '6':
            salida=salida+" -****";
            break;
            case '7':
            salida=salida+" --***";
            break;
            case '8':
            salida=salida+" ---**";
            break;
            case '9':
            salida=salida+" ----*";
            break;
            case '0':
            salida=salida+" -----";
            break;
         }
       }
       Serial.println("Codigo " );
       Serial.println(salida);
       tam1 = salida.length()+1;
       for(k=tam1+1; k>=0;k--){
        String texto = salida.substring(i-1);
        lcd.clear();
        lcd.setCursor(k,1);
        lcd.print(texto);
        delay(1000);
       }
       Serial.println("Ingrese nuevamente el mensaje a codificar");
       lcd.clear();
    }
 }
