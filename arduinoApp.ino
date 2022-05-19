#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
Adafruit_SSD1306 display(-1);


int analogInput = 0;

float Vout = 0.00;
float Vin = 0.00;

float R1 = 100000.00; // resistance of R1 (100K) 
float R2 = 10000.00; // resistance of R2 (10K) 

int val = 0;

void setup(){
   pinMode(analogInput, INPUT);
   Serial.begin(9600);
   Wire.begin();
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop(){
   
   val = analogRead(analogInput);//reads the analog input
   Vout = (val * 5.00) / 1024.00; 
   Vin = Vout / (R2/(R1+R2));
/*   
   if (Vin<0.09) 
   {
     Vin=0.00;
  } 
*/
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("voltage = ");
  display.print(Vin);
  delay(2000);
  display.display();

//Serial.print("\t Voltage of the given source = ");
Serial.println(Vin);

}
