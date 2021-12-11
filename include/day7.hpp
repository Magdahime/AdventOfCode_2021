#pragma once
#include <numeric>
#include <string>
#include <vector>

std::vector<int> getCrabPositions(std::vector<std::string> data);

double getAverage(const std::vector<int> &positions);
int closest(std::vector<int> const &vec, double value);
int64_t getFuelAmount(std::vector<std::string> data);

int64_t getNewFuelAmount(std::vector<std::string> data);