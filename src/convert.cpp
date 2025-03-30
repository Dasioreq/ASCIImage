#include "./convert.hpp"


byte getClosestChar(const float brightness, const bool useWeights)
{
    byte index;

    if(brightness >= gradientWeights[91])
        return chrGradient[91];

    if(useWeights)
        for(int i = 0; i < 92; i++)
        {
            if(i != 0)
                if(gradientWeights[i - 1] < brightness && gradientWeights[i] > brightness)
                {
                    if(brightness - gradientWeights[i - 1] < gradientWeights[i] - brightness)
                        index = i - 1;
                    else
                        index = i;
                    break;
                }
            else if(gradientWeights[i] > brightness)
            {    
                index = i;
                break;
            }
        }
    else
        index = round(brightness * 91);

    return chrGradient[index];
}

std::string convert(const Image& img, const uint16 resultWidth, const bool useWeights)
{
    if(resultWidth > img.getWidth())
        return "";

    const byte kernelSize = floor(img.getWidth() / resultWidth);
    const uint16 resultHeight = floor(img.getHeight() / kernelSize);

    std::string resultBuffer = "";

    for(int y = 0; y <= img.getHeight() - kernelSize; y += kernelSize)
    {
        for(int x = 0; x <= img.getWidth() - kernelSize; x += kernelSize)
        {
            uint32 sum = 0;;
                for(int ky = 0; ky < kernelSize; ky++)
                {
                    for(int kx = 0; kx < kernelSize; kx++)
                    {
                        for(int chnl = R; chnl < 3; chnl++)
                        {
                            //std::cout << chnl << "chnl\n";
                            sum += (uint16)img[(y + ky) * img.getWidth() + x + kx][chnl];
                        }
                        //sum += 0.299f * (uint16)img[(y + ky) * img.getWidth() + x + kx][R] + 0.587 * (uint16)img[(y + ky) * img.getWidth() + x + kx][G] + 0.114 * (uint16)img[(y + ky) * img.getWidth() + x + kx][B];
                    }
                }

            float brightness = sum / (kernelSize * kernelSize * 255.0f * 3.0f);

            resultBuffer += getClosestChar(brightness, useWeights);
            resultBuffer += ' ';
        }

        resultBuffer += '\n';
    }

    return resultBuffer;
}