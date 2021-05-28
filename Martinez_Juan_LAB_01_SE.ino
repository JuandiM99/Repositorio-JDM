/*
 * LABORATORIO I: PUERTOS DIGITALES Y COMUNICACIÓN SERIAL
* CODIGO I
* OBJETIVO: Diseñar un sistema de control de acceso por contraseña individual.
* NOMBRE: Juan Diego Martínez
* FUNCIONES:
  *          LiquidCrystal.h     
*          print(mensaje)  Envío Mensajes
*          setCursor(col,fil)       
*/
  #include <LiquidCrystal.h>;
  #include <Keypad.h>;
  LiquidCrystal lcd (A0,A1,A2,A3,A4,A5); // eleccion de pines 
  const byte f=4;                        // numero de filas
  const byte c=4;                        // numero de columnas
  const int btn=10;                      // variable de control 
  char tecladoM [f][c] = {               // creación de matriz del teclado matricial 
  {'1','2','3','a'},
  {'4','5','6','b'},
  {'7','8','9','c'},
  {'*','0','#','d'}
  };
  byte pinFilas[f] = {9,8,7,6};          // pines de conexion de filas Arduino-Teclado Matricial
  byte pinColum [c] = {5,4,3,2};         // pines de conexion de columnas Arduino-Teclado Matricial
  Keypad tecMat = Keypad(makeKeymap(tecladoM),pinFilas,pinColum,f,c);  // creacion de un objeto de acuerdo a la
  char contrasena[9];                                // vector de la contraseña ingresada
  char contraA[9] = "ad102344";                      // contraseña usuario Ariel Davalos  
  char contraD[9] = "dc774235";                      // contraseña usuario Damian Cervantes 
  char contraC[9] = "ca543187";                      // contraseña usuario Carlos benavides
  byte indice=0;                                     // contador de caracteres de los caracteres ingresados por el teclado matricial
  int i=0;                                           // contador
  int j=0;
  char teclaIng;
  int contA=0;                                       // verificador de registro
  int contD=0;                                       // verificador de registro
  int contC=0;                                       // verificador de registro
  
  void setup() {
  pinMode(btn,INPUT);                               // define el boton como entrada
  Serial.begin(9600);                               // incia la comunicacion serial
  Serial.print("BIENVENIDOS AL SISTEMA DE CONTROL");
  Serial.println(" ");
  lcd.begin(16,2);                                  // inicializa la pantalla lcd
  lcd.clear();                                      // limpia la pantalla lcd
  }

  void loop() {
  
  char teclaIng = tecMat.getKey();                // funcion del teclado matricial
  
  if(teclaIng != NO_KEY)
  {
    Serial.print(teclaIng);                       // se visualiza la tecla ingresada a la terminal por el teclado matricial
    contrasena[indice]=teclaIng;                  // almaceno la tecla en el vector contrasena
    indice++;
  }
  
  if(indice==8)                                   // verificador igual numero de cacteres de contraseña real de cada usuario y la contraseña ingresada
  {
    byte veriA=0;                                 // contador de caracteres para la cotraseña 1 
    byte veriD=0;                                 // contador de caracteres para la cotraseña 2
    byte veriC=0;                                 // contador de caracteres para la cotraseña 3
  
    for(i=0;i<8;i++)                              // ciclo for para verificar cada caracter de la contraseña 
    {
      // Serial.print(contrasena[i]);                // imprimi la contraseña ingresada y a verificar
      if(contrasena[i]==contraA[i])               // verificacion de la contraseña usuario Arial Davalos
      {
        veriA++;
      }
        if(contrasena[i]==contraD[i])               // verificacion de la contraseña usuario Damian Cervantes
      {
        veriD++;
      }
      if(contrasena[i]==contraC[i])               // verificacion de la contraseña usuario Carlos Benavides
      {
        veriC++;
      }
    }
  
     if(veriA==8)                                    // verificar que los cacteres de contraseña real de cada usuario y de la contraseña ingresada sean los mismos
     {
        Serial.println(" ");
        Serial.print("CONTRASENIA CORRECTA");
        lcd.setCursor(1,0);                           // inicializo en LCD
        lcd.print("BIEN VENIDO");                     // mensaje de bienvenida
        lcd.setCursor(1,1);                           // inicializo en LCD
        lcd.print("Ariel Davalos");   
        Serial.println(" ");
        contA=1;                  
     }
  
     if(veriD==8)                                     // verificar que los cacteres de contraseña real de cada usuario y de la contraseña ingresada sean los mismos
     {
        Serial.println(" ");
        Serial.print("CONTRASENIA CORRECTA");
        lcd.setCursor(1,0);                           // inicializo en LCD
        lcd.print("BIEN VENIDO");                     // mensaje de bienvenida
        lcd.setCursor(1,1);                           // inicializo en LCD
        lcd.print("Damian Cervantes");  
        Serial.println(" "); 
        contD=1;        
     }
  
     if(veriC==8)
     {
        Serial.println(" ");
        Serial.print("CONTRASENIA CORRECTA");           // verificar que los cacteres de contraseña real de cada usuario y de la contraseña ingresada sean los mismos
        lcd.setCursor(1,0);                             // inicializo en LCD
        lcd.print("BIEN VENIDO");                       // mensaje de bienvenida
        lcd.setCursor(1,1);                             // inicializo en LCD
        lcd.print("Carlos Benavides");
        Serial.println(" ");
        contC=1;
     }
  
     if(veriA==8 || veriD==8 || veriC== 8)
     {
     }else{
      Serial.println(" ");
      Serial.print("CONTRASENIA NO VALIDA");
      lcd.setCursor(0,0);
      lcd.print("CONTRASENIA INCORRECTA");
     }
     indice=0;
     for(j=0;j<18;j++)
     {
      lcd.setCursor(16,1);
      lcd.autoscroll();
      lcd.print(" ");
      delay(100);
     }
     lcd.clear();       
  }

  if(digitalRead(btn)==LOW){              //Activación de botón en bajo para la lista de ingresados.
  delay(100);
  if(contA==1){
    Serial.println("Ariel Davalos HA INGRESASDO");               //Muestra en la terminal los usuarios que han ingresado y los que no
  }else{                
    Serial.println("Ariel Davalos NO HA INGRESASDO");
  }
  if(contD==1){
    Serial.println("Damian Cervantes HA INGRESASDO");
  }else{
      Serial.println("Damian Cervantes NO HA INGRESASDO");
  }
  if(contC==1){
    Serial.println("Carlos Benavides HA INGRESASDO");
  }else{
    Serial.println("Carlos Benavides NO HA INGRESASDO");
  }
  }
}
