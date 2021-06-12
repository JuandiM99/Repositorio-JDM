/*
 * Deber 6.1: Reto 3
 * Nombre: Juan Diego Martínez
 */
void setup() {
pinMode(7,INPUT);
Serial.begin(9600);     //Inicialización de comunicación serial a 9600 baudios
}
void loop() {                            
Serial.println(digitalRead(7));  // Transfiere a través del puerto serial el estado digital del pin 0
delay(500);
}
