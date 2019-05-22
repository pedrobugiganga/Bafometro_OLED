#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>


// Definicao de pinos interface SPI
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define entrada_sensor A0
int sensor_temp;
int i =0;
float temp;

#define SSD1306_LCDHEIGHT 64
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


void setup()   
{
  
  display.clearDisplay();
  Serial.begin(9600);
   pinMode(entrada_sensor, INPUT);
  // Inicializa o display
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextColor(WHITE);



  for(i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, WHITE);
    display.display();
    delay(1);
  }
  delay(2000);

  display.clearDisplay();

  //*********************************
  display.setCursor(0,0);
  display.println("   AQUECENDO SENSOR");
  display.display();
  delay(4000);
  display.clearDisplay();

  display.setCursor(0,0);
  display.println("   AQUECENDO SENSOR");
  display.display();

  display.setCursor(0,20);
  display.println("EU BEBO..");
  display.display();
  delay(1000);
  display.clearDisplay();
  delay(500);

  display.setCursor(0,0);
  display.println("   AQUECENDO SENSOR");
  display.display();
  display.setCursor(0,30);
  display.println("   TU BEBES..");
  display.display();
  delay(1500);
  display.clearDisplay();
  delay(500);

  display.setCursor(0,0);
  display.println("   AQUECENDO SENSOR");
  display.display();
  display.setCursor(0,40);
  display.println("    ELE BEBE..");
  display.display();
  delay(1500);
  display.clearDisplay();
  delay(500);

   display.setCursor(0,0);
  display.println("   AQUECENDO SENSOR");
  display.display();
  display.setCursor(40,40);
  display.println("NOS BEBEMOS..");
  display.display();
  delay(1500);
  display.clearDisplay();
  delay(500);

  display.setCursor(0,0);
  display.println("   AQUECENDO SENSOR");
  display.display();
  display.setCursor(20,20);
  display.println("      VOS BEBEIS..");
  display.display();
  delay(1500);
  display.clearDisplay();
  delay(500);

  display.setCursor(0,0);
  display.println("   AQUECENDO SENSOR");
  display.display();
  display.setCursor(0,40);
  display.println("   ELES BEBEM..");
  display.display();
  delay(1500);
  display.clearDisplay();
  delay(500);
  display.setCursor(0,20);
  display.println("   BORA, TUMA UMA !?");
  display.display();
  delay(4000);
  display.clearDisplay();

//*********************************


  delay(1000);
  display.clearDisplay();
}

void loop() 
{
  int tempM[500]; // medição média
  int j=0 ;
  for(j =0; j<500; j++){
  sensor_temp = analogRead(entrada_sensor);
   tempM [j] = sensor_temp;
   temp=temp+tempM[j];
  }

 int temp_result = temp / 500;


  display.clearDisplay();
  display.setFont(&FreeSansBold9pt7b);
  display.setTextSize(1);
  display.setCursor(0,15);
  display.println("  BAFOMETRO");
  display.setFont(&FreeSansBold18pt7b);
  display.setTextSize(1);
  display.setCursor(30,40);
  display.print(">");
  display.setFont(&FreeSans18pt7b);
  display.setCursor(70,45);
  display.print(temp_result);
  

  Serial.println(temp_result);
  Serial.println();
  
  temp = 0;



 if (temp_result >= 0 and temp_result <= 140)
  {
  display.setFont();
  display.setCursor(0,55);
  display.setTextSize(1);
  //display.print("                    ");
  display.print(" Voce nao bebeu...");
 // display.display();
  }
  else if (temp_result >= 141 and temp_result <= 200)
  {
    display.setFont();
  display.setCursor(0,55);
  display.setTextSize(1);
  //display.print("                    ");
  display.print(" Bebeu 1 cerveja ?");
  //display.display();
  }
  else if (temp_result >= 201 and temp_result <= 400)
  {
    display.setFont();
  display.setCursor(0,55);
  display.setTextSize(1);
  //display.print("                    ");
  display.print(" Bebeu 2 cervejas ?");
 // display.display();
  }
  else if (temp_result >= 401 and temp_result <= 500)
  {
    display.setFont();
  display.setCursor(0,55);
  display.setTextSize(1);
  //display.print("                    ");
  display.print(" Voce cheira a 51 !");
  //display.display();
  }
  else if (temp_result >= 501)
  {
    display.setFont();
  display.setCursor(0,55);
  display.setTextSize(1);
  //display.print("                    ");
  display.print(" Voce esta bebado !!");
  //display.display();
  }

//delay(80);
display.display();

  
}
