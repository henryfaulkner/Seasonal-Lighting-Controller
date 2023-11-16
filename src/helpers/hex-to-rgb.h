#ifndef HEX_TO_RGB_H
#define HEX_TO_RGB_H

class HexToRgb
{
public:
    int *ConvertHexToRGBArray(unsigned long hexValue)
    {
        // Extract individual components (R, G, B) from the hex value
        int r = (hexValue >> 16) & 0xFF;
        int g = (hexValue >> 8) & 0xFF;
        int b = hexValue & 0xFF;

        // Allocate an array to store the RGB values
        int *rgbArray = new int[3]{r, g, b};

        return rgbArray;
    }
};

#endif // HEX_TO_RGB_H