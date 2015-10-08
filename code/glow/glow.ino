#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels(2,0,NEO_GRB+NEO_KHZ800);
int color=1;

void glow(const int color)
{
  for(int ii=0;ii<255;++ii)
  {
    pixels.setPixelColor(0,pixels.Color(ii*(1&color),ii*(2&color)/2,ii*(4&color)/4));
    pixels.setPixelColor(1,pixels.Color(ii*(1&color),ii*(2&color)/2,ii*(4&color)/4));
    pixels.show();
    delay(2);
  }

  delay(100);

  for(int ii=255;ii>=0;--ii)
  {
    pixels.setPixelColor(0,pixels.Color(ii*(1&color),ii*(2&color)/2,ii*(4&color)/4));
    pixels.setPixelColor(1,pixels.Color(ii*(1&color),ii*(2&color)/2,ii*(4&color)/4));
    pixels.show();
    delay(2);
  }
}

void setup()
{
  pixels.begin();
  pinMode(4,INPUT_PULLUP);
}

void loop()
{
  if(!digitalRead(8))
  {
    for(int ii=0;ii<3;++ii)
      glow(color);

    color*=2;

    if(color<=0||color>4)
      color=1;
  }
}
