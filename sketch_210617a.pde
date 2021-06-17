import processing.serial.*;
boolean estadoBoton = false;
Serial miSerial;
void setup(){
  String nombrePuerto = "COM1";
  miSerial = new Serial (this,nombrePuerto,9600);
  size(400,400);
}

void draw()
{
  if(estadoBoton)
  {
    fill(#B4123E);
  }
  else
  {
    fill(#12B42B);
  }
  ellipse(200,200,200,200);
}

void mouseClicked(){
  float distancia = dist(200,200,mouseX,mouseY);
  if(distancia <135)
  {
      estadoBoton=!estadoBoton;
        miSerial.write('a');
  }
  
}
