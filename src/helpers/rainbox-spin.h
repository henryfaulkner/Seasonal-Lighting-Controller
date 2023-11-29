#ifndef RAINBOW_SPIN_H
#define RAINBOW_SPIN_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class RainbowSpin
{
public:
    void Rainbow(Adafruit_NeoPixel strip, int ledCount)
    {
        Serial.println("method::Rainbow");
        for (int i = 0; i < ledCount; i++)
        {
            int pixel_index = (floor((i * 256) / ledCount));
            strip.setPixelColor(i, Wheel(strip, pixel_index & 255));
            strip.show();
            delay(10);
        }
    }

    uint32_t Wheel(Adafruit_NeoPixel strip, int pos)
    {
        int r;
        int g;
        int b;
        if (pos < 0 || pos > 255)
        {
            r = 0;
            g = 0;
            b = 0;
        }
        else if (pos < 85)
        {
            r = floor(pos * 3);
            g = floor(255 - pos * 3);
            b = 0;
        }
        else if (pos < 170)
        {
            pos = pos - 85;
            r = floor(255 - pos * 3);
            g = 0;
            b = floor(pos * 3);
        }
        else
        {
            pos = pos - 170;
            r = 0;
            g = floor(pos * 3);
            b = floor(255 - pos * 3);
        }
        return strip.Color(g, r, b);
    }
};

#endif RAINBOW_SPIN_H