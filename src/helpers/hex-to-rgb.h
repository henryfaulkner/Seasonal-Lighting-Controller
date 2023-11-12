#ifndef HEX_TO_RGB_H
#define HEX_TO_RGB_H

int hexCharToDecimal(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'F')
    {
        return 10 + c - 'A';
    }
    else if (c >= 'a' && c <= 'f')
    {
        return 10 + c - 'a';
    }
    else
    {
        return -1;
    }
}

int *ConvertHexToRGBArray(unsigned int hexValue)
{
    // Extract individual components (R, G, B) from the hex value
    int r = (hexValue >> 16) & 0xFF;
    int g = (hexValue >> 8) & 0xFF;
    int b = hexValue & 0xFF;

    // Allocate an array to store the RGB values
    int *rgbArray = new int[3]{r, g, b};

    return rgbArray;
}

#endif HEX_TO_RGB_H