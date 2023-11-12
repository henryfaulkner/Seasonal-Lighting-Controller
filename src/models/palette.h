#include "../helpers/hex-to-rgb.h"

#ifndef PALETTE_H
#define PALETTE_H

class Palette
{
public:
    virtual ~Palette() = default;
    // virtual Palette &operator=(const Palette &other);
    void Run();
};

#endif PALETTE_H