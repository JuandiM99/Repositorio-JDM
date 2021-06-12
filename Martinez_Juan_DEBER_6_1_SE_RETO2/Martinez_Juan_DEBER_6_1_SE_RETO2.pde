//SISTEMAS EMBEBIDOS
// DEBER 6.1 RETO 1
// Nombre: Juan Diego Martínez
int
  i=250;
void setup() {
  size(400, 400);                            // tamaño de la pantalla 
  background(#9b9b9b);                       // color de pantalla
  textSize(20);                              // tamaño de letra
  fill(0);                                   // color de letra
  text("Presione el Botón para ", 100, 50);  // mensaje de inicio
  text("Encender o Apagar el LED", 90, 70);  // mensaje de inicio
  smooth();
  fill(#FF0000);                             // color del circulo inicial
  ellipse(200, 200, 200, 200);               // función del circulo posicion y tamaños
  textSize(20);                              // tamaño de letra
  fill(250);                                 // color de letra
  text("!Apagado¡", 150, height/2);          // mensaje y posicion del texto
}
void draw() {                                // método de dibujo
  noStroke();
}
// CREACIÓN DE MÉTODOS CUANDO SE PRESIONE EL MOUSE 
void mousePressed() {                        
  if (mouseButton==RIGHT) {                  // boton derecho del mouse
    fill(#804000);                           // color del circulo
    ellipse(200, 200, 200, 200);             // función del circulo posicion y tamaños
  }
  if (mouseButton == LEFT) {                 // boton derecho del mouse
      fill(#006400);                         // color del circulo
    ellipse(200, 200, 200, 200);             // función del circulo posicion y tamaños
  }
}
// MÉTODOS CUANDO SE DEJE DE PRESIONAR EL MOUSE  
void mouseReleased() {
  if (mouseButton==RIGHT) {                  // caso del boton derecho            
    fill(#ff0000 );
    ellipse(200, 200, 200, 200);
    textSize(20);
    fill(250);
    text("!Apagado¡", 150, height/2);
  }
  if (mouseButton == LEFT) {                 // caso del boton izquierdo
    fill(#00ff00);
    ellipse(200, 200, 200, 200);
    textSize(20);
    fill(250);
    text("!Encendido¡", 150, height/2);
  }
}
