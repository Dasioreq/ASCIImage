#include "./image.hpp"

Image::Image()
{
    *texture = nullptr;
    texture = nullptr;
}

Image::Image(const byte* STBIOutputString, const uint16 width, const uint16 height, const byte channels): width(width), height(height), channels(channels)
{
    uint32 imageSize = width * height;
    texture = new byte*[imageSize];

    for(int i = 0; i < imageSize; i++)
    {
        texture[i] = new byte[channels];
    }

    for(int px = 0; px < imageSize; px++)
    {
        for(byte channel = 0; channel < channels; channel++)
        {
            texture[px][channel] = STBIOutputString[px * channels + channel];
        }
    }
} 

Image::Image(const uint16 width, const uint16 height, const byte channels): width(width), height(height), channels(channels)
{
    texture = new byte*[width * height];

    for(int i = 0; i < width * height; i++)
    {
        texture[i] = new byte[channels];
    }
}

Image::~Image()
{
    delete[] texture;
}

uint16 Image::getWidth() const
{
    return this -> width;
}
uint16 Image::getHeight() const
{
    return this -> height;
}
uint16 Image::getChannels() const
{
    return this -> channels;
}

void Image::setWidth(const uint16 width, const bool reset)
{
    this -> width = width;

    if(reset)
        this -> resetTexture();
}
void Image::setHeight(const uint16 height, const bool reset)
{
    this -> height = height;

    if(reset)
        this -> resetTexture();
}
void Image::setChannels(const uint16 channels, const bool reset)
{
    this -> channels = channels;
        
    if(reset)
        this -> resetTexture();
}

void Image::resetTexture()
{
    texture = new byte*[width * height];

    for(int i = 0; i < width * height; i++)
    {
        texture[i] = new byte[channels];
    }
}

byte* Image::operator[](const uint32 pxIndex) const
{
    if(pxIndex >= width * height)
        return 0;
    return texture[pxIndex];
}

// Image resize(const Image img, const uint16 newWidth)
// {
//     uint16 
//         origWidth = img.getWidth(), 
//         origHeight = img.getHeight(),
//         newHeight;

//     Image newImg;

//     if(newWidth < img.getWidth())
//     {
//         uint16 kernelSize = floor(origWidth / newWidth);
//         newHeight = floor(origHeight / kernelSize);

        
//     }
// }