#pragma once

enum RGBA
{
    R = 0,
    G = 1, 
    B = 2, 
    A = 3
};

typedef unsigned char byte;
typedef signed char sbyte;
typedef unsigned long long uint64;
typedef signed long long int64;
typedef unsigned long uint32;
typedef signed long int32;
typedef unsigned short uint16;
typedef signed short int16;

extern const char* chrGradient;
extern const float gradientWeights[92];