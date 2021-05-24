#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11); // Definimos los pines RX y TX del Arduino conectados al Bluetooth
SoftwareSerial ArdOx(8,9);
String nombre=""; 
char letra;
double ox;


void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie  
 ArdOx.begin(9600);
  mlx.begin();  
}
 
void loop()
{

  if(ArdOx.available())
  {
    ox=ArdOx.read();
    
    }
  
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    letra=BT.read();
    nombre=nombre+letra;
    if(letra=='.')
    {
     Serial.print(nombre+"\t");
     nombre="";
     Serial.print(mlx.readObjectTempC());

     Serial.print("°C");
     Serial.print("\t");
     Serial.println(ox);
      }
  }

  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }
}
