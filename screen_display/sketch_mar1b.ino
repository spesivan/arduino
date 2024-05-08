#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);
char bufferX [20];
char bufferY [20];
char bufferZ [20];
void setup() {

}

void loop() {
  sprintf(bufferX, "     SELAM");
  sprintf(bufferY, "    GUZELLIK");
  sprintf(bufferZ, "       <3");
  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() );
  delay(10);
}

// void loop() {
//   // Ekran temizle
//   u8g.firstPage();
//   do {
//     // Metni ekrana yazdır
//     u8g.setFont(u8g_font_6x10);
//     u8g.drawStr(20, 20, "Merhaba, dunya!");
//   } while( u8g.nextPage() );
  
//   // Bekleme süresi
//   delay(1000);
// }


void draw(void)
{


  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 20, bufferX);
  u8g.drawStr( 0, 40, bufferY);
  u8g.drawStr( 0, 60, bufferZ);
}
