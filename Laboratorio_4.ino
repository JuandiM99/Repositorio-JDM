/*
*  UNIVERSIDAD TECNICA DEL NORTE
*  SISTEMAS EMBEBIDOS
*  STEVEN FLORES
*  5to CITEL
* Laboratorio 4
*/
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
int col = 0; //Moverse en columnas
int fil = 0; //Moverse en filas
float Ex=0;   //Sumatoria x
float Yp=0;   //Y prima
float Eyp=0;   //Sumatoria y prima  
float Exyp=0;     //Sumatoria xyprima
float Ex2=0;   //Sumatoria x^2
float Ex_2=0;    //(Sumatoria x)^2
int n = 23; //tam muestras
float Bo; //ordenada en el origen
float m; //pendiente
String dato; //Recibir estatura
int estatura; //Convertir dato
float peso; 
float m1; //aux
void setup() {
    Serial.begin(9600);
    serialDigit.begin(9600);
    //Creacion del modelo
    for(;fil<n;fil++){
      Ex=Ex+matriz[fil][0];
      Yp=(log(matriz[fil][1]));
      Eyp=Eyp+Yp;
      Exyp=Exyp+(matriz[fil][0]*Yp);
      Ex2=Ex2+pow(matriz[fil][0],2);    
    }
    Ex_2=pow(Ex,2);
    Bo=(float(n*Exyp)-float(Ex*Eyp))/(float(n*Ex2-Ex_2));
    m1=(Eyp/14)-(Bo*(Ex/14));
    m=float(exp(m1));
    Serial.println("El modelo es :");
    Serial.println(String("y = ")+String(m)+String("* exp(")+String(Bo)+String("* x)"));
    Serial.println("Ingrese su estatura: ");
}

void loop() {
  
    dato=analogRead(0);
    estatura = dato.toInt();
    peso = m*exp(estatura*Bo);
    Serial.println("");
    Serial.println(String("Su peso es : ")+String(peso)+String("Kg"));
    Serial.println("Ingrese su estatura: "); 
    serialDigit.write(estatura);
    delay(250);

  
}
