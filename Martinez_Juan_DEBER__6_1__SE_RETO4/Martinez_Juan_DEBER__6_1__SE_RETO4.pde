// SISTRMAS EMBEBIDOS
// Deber 6.1
// Nombre: Juan Diego Martínez

import processing.serial.*;
Serial puerto; 

void setup() {                                            // objetvo para la comunicación serial
  puerto = new Serial (this, "COM6", 9600);               // se fedine la comunicacion con el puerto y la velocidad de transmision 
  background(#9b9b9b);
  size(400, 400);                                         // tamaño de pantañña                
  textSize(5);
  textSize(20);
  fill(0);
  text("Presione el Botón para", 100, 30);                // Mensaje de principal en la pantalla
  text("Encender o Apagar el Led", 90, 50);               // Mensaje de principal en la pantalla
  fill(#FF0000);                                          // color de letra
  ellipse(200, 200, 200, 200);                            // creación del circulo
  fill(250);
  text("¡Apagado¡",width/2-50, height/2);                 // mensaje de inicio
}

void draw() {
}

void mousePressed() {
  float distancia=dist(mouseX, mouseY, 200, 200);        // variable para determinar la distancia que este dentro del círculo
  if (distancia<100)                                     // si esta dentro del círculo
  {
    fill(#008000);                                       // color del circulo
    ellipse(200, 200, 200, 200);                         // creaciñon de circulo encendido
    puerto.write('e');                                   // 
    fill(250);                                           // color de letra
    text("¡Encendido¡", width/2-50, height/2);           // mensaje
  }
}

void mouseReleased() {
  float distancia=dist(mouseX, mouseY, 200, 200);        // variable para determinar la distancia que este dentro del círculo
  if (distancia<100)                                     // si esta dentro del círculo
  {  
    fill(#FF0000);                                       // color del circulo
    ellipse(200, 200, 200, 200);                         // creaciñon de circulo encendido
    puerto.write('a');
    fill(250);                                           // color de letra
    text("!Apagado¡", width/2-50, height/2);             // mensaje
  }
}
