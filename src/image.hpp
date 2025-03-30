#pragma once
#include "typedefs.hpp"
#include <math.h>
#include <iostream>

struct Image
{
private:
    byte** texture;
    uint16 width, height, channels;  
public:
    Image();
    Image(const byte* STBIOutputString, const uint16 width, const uint16 height, const byte channels);
    Image(const uint16 width, const uint16 height, const byte channels);

    ~Image();

    uint16 getWidth() const;
    uint16 getHeight() const;
    uint16 getChannels() const;

    void setWidth(const uint16 width, const bool reset);
    void setHeight(const uint16 height, const bool reset);
    void setChannels(const uint16 channels, const bool reset);

    void resetTexture();

    byte* operator[](const uint32 pxIndex) const;
};  

Image resize(const uint16 newWidth);