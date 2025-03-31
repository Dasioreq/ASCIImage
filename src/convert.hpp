#pragma once
#include "./image.hpp"

/**
 * Does stuff
 * @param {Number} params 
 */
char getClosestChar(const float brightness, const bool useWeights = true);

std::string convert(const Image& img, const uint16 resultWidth, const bool useWeights = true);