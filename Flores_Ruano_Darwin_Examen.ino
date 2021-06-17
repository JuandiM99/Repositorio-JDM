/*
*  UNIVERSIDAD TECNICA DEL NORTE
*  SISTEMAS EMBEBIDOS
*  STEVEN FLORES
*  5to CITEL
*  EVALUACCION SEGUNDO BIMESTRE
*  25-01-2021
*/
#include<avr/power.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include<EEPROM.h>
#include <SoftwareSerial.h>
SoftwareSerial serialDigit(2,3); // RX, TX
float matriz[23][2]={
  {89,7.8},
  {67,7.5},
  {45,7.4},
  {67,7.5},
  {45,6.9},
  {78,6.8},
  {123,6.5},
  {187,5.5},
  {190,5.6},
  {245,4.7},
  {267,4.7},
  {367,4.5},
  {398,4.3},
  {467,4.3},
  {478,4.3},
  {674,4.0},
  {756,3.6},
  {756,3.7},
  {821,3.5},
  {834,3.4},
  {914,3.5},
  {945,3.6},
  {977,3.3}
};
int col = 0; 
int fil = 0; 
float Elogx=0;   
float Elogy=0;   
float Exy=0;   
float Elogx_2=0;     
int n = 23; 
float B; 
float A; 
String dato; 
int CAD; 
float TIEMPO; 
float aux; //aux
int dato1;
int i;
float k;
void (* resetFunc)(void)=0;
void setup() {
  //EEPROM.write(0,0);
  //EEPROM.write(2,0);
  dato1=EEPROM.read(0);
  k=EEPROM.read(2);
  Serial.begin(9600);
  if(dato1==0){
    Serial.begin(9600);
    serialDigit.begin(9600);
    potencial();
    EEPROM.write(1,0);
    i=EEPROM.read(1);
  }else{
    i=EEPROM.read(1);
    i=i+1;
    EEPROM.update(1,i);
  }
  if(i<4){        //(7.6*2) * 500MS = 7600MS
  delay(100);
  modo();
  }else{
    EEPROM.update(0,0);
    wdt_enable(WDTO_15MS);
  }
    
}

void loop() {    
    
}
void potencial(){
      //Creacion del modelo potencial
    for(;fil<n;fil++){
      Elogx=Elogx+log10(matriz[fil][0]);
      Elogy=Elogy+(log10(matriz[fil][1]));
      Exy=Exy+(log10(matriz[fil][0])*log10(matriz[fil][1]));
      Elogx_2=Elogx_2+pow(log10(matriz[fil][0]),2);    
    }
    Serial.println(Elogx);
    Serial.println(Elogy);
    Serial.println(Exy);
    Serial.println(Elogx_2);
    B=(float(n*Exy)-float(Elogx*Elogy))/(float(n*Elogx_2-pow(Elogx,2)));
    aux=(float(Elogy/n)-float(B*Elogx/n));
    A=float(pow(10,aux));
    Serial.println("El modelo es :");
    Serial.println(String("y = ")+String(A)+String(" * X^(")+String(B)+String("}"));
      CAD = analogRead(0);
    TIEMPO = A*(pow(CAD,B));
    Serial.println("");
    Serial.println(String("El tiempo de perro guardian es : ")+String(TIEMPO)+String("s"));
    serialDigit.write(TIEMPO);
    delay(500);
    EEPROM.update(0,1);
    EEPROM.update(0,2);
}
void modo(){
    wdt_enable(WDTO_1S);
    set_sleep_mode(SLEEP_MODE_PWR_SAVE);
    sleep_enable();
    sleep_mode();
    sleep_disable();
    wdt_disable();
}
void encender(){
  resetFunc();
}
