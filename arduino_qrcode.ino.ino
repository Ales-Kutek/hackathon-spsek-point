#include <qrcode.h>

#include <Adafruit_TFTLCD.h>
#include <pin_magic.h>
#include <registers.h>
#include <Adafruit_GFX.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);

  
  Serial.begin(115200);
  uint32_t dt = millis();
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(3)];
  qrcode_initText(&qrcode, qrcodeData, 3, 3, "TESTTEST");

  dt = millis() - dt;
  tft.fillScreen(WHITE);
  for (uint8_t y = 0; y < qrcode.size; y++) {
      
        // Each horizontal module
        for (uint8_t x = 0; x < qrcode.size; x++) {

            // Print each module (UTF-8 \u2588 is a solid block)
            if(qrcode_getModule(&qrcode, x, y))
            {
              tft.fillRect(x*7, y*7, 7, 7, BLACK);  
            }
            else
            {
             
            }

        }

        Serial.print("\n");
    }
  
}

void loop() {
  // put your main code here, to run repeatedly:
        
    
  
}


