#include <iostream>
#include <stdint.h>
#include "day2.hpp"

int64_t getDirections(std::vector<std::string> data) {
  int64_t hPos = 0, depth = 0, aim = 0;
  for (auto elem : data) {
    switch (elem.front()) {
    case 'f': {
      int64_t value = std::stoi(elem.substr(7));
      hPos += value;
      depth += aim * value;
      break;
    }
    case 'd': {
      aim += std::stoi(elem.substr(4));
      break;
    }
    case 'u': {
      aim -= std::stoi(elem.substr(2));
      break;
    }
    default:
      break;
    }
  }
  return hPos * depth;
}