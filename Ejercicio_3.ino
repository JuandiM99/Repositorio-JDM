/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FACULTAD DE INGENIERIA EN CIENCIAS APLICADAS
 * SISTEMAS EMBEBIDOS
 * STEVEN FLORES
 * 5to Nivel; 
 * EXAMEN BIMESTRAL : Ejercicio 3
 */
 #include<Servo.h>
 Servo servo;   //Objeto para servo 1
 int giro;
 const int A=8;
 const int B=9;
 const int C=10;
 const int D=11;
 const int E=12;
 int i=0;
 int on=0;
 String aux;
 void  setup(){
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  pinMode(C,INPUT);
  pinMode(D,INPUT);
  pinMode(E,INPUT);
  servo.attach(6);
  servo.write(0);
  attachInterrupt(0,activacion,LOW);
  Serial.begin(9600);
  
 }
 void loop(){
   switch(on){
    case 1:
      if(digitalRead(A)==LOW){
        delay(300);
        aux = aux + "1";
        i++;
        Serial.println("Boton registrado");
      }
      if(digitalRead(B)==LOW){
        delay(300);
        aux = aux + "2";
        i++;
        Serial.println("Boton registrado");
      }
      if(digitalRead(C)==LOW){
        delay(300);
        aux = aux + "3";
        i++;
        Serial.println("Boton registrado");
      }
      if(digitalRead(D)==LOW){
        delay(300);
        aux = aux + "4";
        i++;
        Serial.println("Boton registrado");
      }
      if(digitalRead(E)==LOW){
        delay(300);
        aux = aux + "5";
        i++;
        Serial.println("Boton registrado");
      }
      break;
    case 2:
      if(i==5){
        if(String(aux)=="24153"){
          Serial.println("Secuencia correcta, moviendo el motor");
          servo.write(100);
          on=0;
        }else{
          Serial.println("Secuencia incorrecta, Ingrese la secuencia correcta");
          aux="";
          i=0;
          on=1;
        }
      }else{
        Serial.println("Secuencia incorrecta, Ingrese la secuencia correcta");
        aux="";
        i=0;
        on=1;
      }
      break;
    }
  }

 void activacion (){
  switch(on){
    case 0:
    Serial.println("Ingrese la secuencia de botones");
    Serial.println("Presione nuevamente para comprobar la secuencia");
    on++;
    delay(300);
    break;
    case 1: 
    Serial.println("Secuencia Ingresada");
    Serial.println(aux);
    Serial.println("Verificando");
    on++;
    break;
  }
 }
