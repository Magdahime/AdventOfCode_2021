#pragma once
#include "day6.hpp"
#include <stdint.h>
#include <string>
#include <vector>


std::vector<int8_t> prepareFishColony(std::vector<std::string> data);
void calculateDay(std::vector<int8_t> &fishColony);
uint64_t getNumberOfFishesTrivial(std::vector<std::string> data, uint64_t days);
uint64_t getNumberOfFishes(std::vector<std::string> data, uint64_t days);
void iterate(std::vector<uint64_t>& fishMapping);