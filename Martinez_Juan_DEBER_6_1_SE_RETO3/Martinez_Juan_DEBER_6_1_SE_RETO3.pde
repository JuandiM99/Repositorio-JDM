/*
 * Deber 6.1: Reto 3
 * Nombre: Juan Diego Martínez
 */
import processing.serial.*;                        // libreria de comunicaciñon serial
Serial miPuerto;                                   // creación del método para la comunicación serial
void setup() {  
  size(300, 300);                                  // pantalla y tamaño                            
  miPuerto = new Serial(this, "COM6", 9600);       // nuevo objeto de comunicación serial y velocidad
}
void draw() {
  char dato = miPuerto.readChar();                 // almacenamineto del dato leido en comunicacióon serial 
  if (dato=='1')                                   // condición de pulsado
  {
    fill(#00FF00);                                 // color de circulo
    ellipse(150, 150, 150, 150);                   // posicion y dimension del circulo
    fill(0);
    text("!Prendido¡", 125, 150);                  // mensaje
  } else
  {
    if (dato=='0')                                 // condición de no pulsado
    {  
      fill(#FF0000);                               // color de circulo
      ellipse(150, 150, 150, 150);                 // posicion y dimension del circulo
      fill(0);  
      text("!Apagado¡", 125, 150);                 // mensaje
    }
  }
}
