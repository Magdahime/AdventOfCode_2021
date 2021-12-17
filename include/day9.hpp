#pragma once
#include <stdint.h>
#include <string>
#include <vector>

std::vector<std::vector<short>> buildHeightMap(std::vector<std::string> data);
std::vector<short> getLowPoints(std::vector<std::vector<short>> heightMap);
int64_t calculateSumOfLowPoints(std::vector<short> lowPoints);

int64_t getSumOfLowPoints(std::vector<std::string> data);
