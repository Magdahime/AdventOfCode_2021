#pragma once
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <stdint.h>
#include <string>
#include <vector>

std::vector<std::string> loadDataFromFile(std::string filename);

std::vector<int64_t> convertStringVector(std::vector<std::string> data);

template <typename T>
uint64_t countIncrease(const std::vector<T> data, uint32_t range) {
  uint64_t counter = 0;
  for (auto it = data.begin(); it != data.end() - range; it++) {
    uint64_t sum1 = std::accumulate(it, it + range, 0);
    uint64_t sum2 = std::accumulate(it + 1, it + 1 + range, 0);
    if (sum1 < sum2) {
      counter++;
    }
  }
  return counter;
}