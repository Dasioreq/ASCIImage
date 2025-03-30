#include "./src/convert.hpp"
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "./lib/stb_image.h"

int main()
{
    int height, width, channels;

    std::string imgPath;
    std::cout << "Input path to image (Accepted formats: .jpeg, .png, .bmp, .hdr, .psd, .tga, .gif, .pic, .pgm, .ppm): ";
    std::cin >> imgPath;
    std::cin.clear();

    byte* buffer2 = stbi_load(imgPath.c_str(), &width, &height, &channels, 0);
    while(buffer2 == NULL)
    {
        std::cout << "Failure reason: " << stbi_failure_reason() << '\n';
        std::cout << "Invalid path, unsupported image format (.jpeg, .png, .bmp, .hdr, .psd, .tga, .gif, .pic, .pgm, .ppm) or corrupted file. Input correct path: ";
        std::cin >> imgPath;
        std::cin.clear();
    
        buffer2 = stbi_load(imgPath.c_str(), &width, &height, &channels, 0);
    }

    Image* img = new Image(buffer2, width, height, channels);
    
    uint16 resultChartWidth;
    std::string validationBuffer;
    std::cout << "Input the result image width in characters: ";
    std::cin >> validationBuffer;
    std::cin.clear();

    resultChartWidth = std::stoi(validationBuffer);

    std::string medium;
    std::cout << "Input character (or a set of characters) to be printed inbetween the characters of the resulting image (to stretch it out horizontally a single space is recommended): ";
    std::cin >> medium;
    std::cin.clear();

    std::cout << convert(*img, resultChartWidth);

    delete[] buffer2;
    delete img;
}   