#include "day3.hpp"
#include <stdint.h>

int64_t getGammaEpsilon(std::vector<std::string> data) {
  std::stringstream gamma;
  std::stringstream epsilon;
  for (int i = 0; i < data[0].size(); i++) {
    auto sum = std::count_if(data.begin(), data.end(),
                             [&](std::string &elem) { return elem[i] == '1'; });
    if (sum > data.size() / 2) {
      gamma << "1";
      epsilon << "0";
    } else {
      gamma << "0";
      epsilon << "1";
    }
  }
  uint64_t gammaValue = std::stoi(gamma.str(), nullptr, 2);
  uint64_t epsilonValue = std::stoi(epsilon.str(), nullptr, 2);
  return gammaValue * epsilonValue;
}

int64_t getO2(std::vector<std::string> data) {
  for (int i = 0; i < data[0].size(); i++) {
    std::vector<std::string> one;
    std::vector<std::string> zero;
    for (auto &elem : data) {
      if (elem[i] == '1') {
        one.emplace_back(std::move(elem));
      } else {
        zero.emplace_back(std::move(elem));
      }
    }
    if (one.size() >= zero.size()) {
      data = one; // ZAPYTAĆ BARTUSIA CZY TO JEST LEGAL - tzn. czy to nie jest
                  // jakieś ultra zjebane
    } else {
      data = zero;
    }
  }
  if (data.size() != 1) {
    throw std::runtime_error("Error! O2 It should be only one left");
  }
  return std::stoi(data.front(), nullptr, 2);
}

int64_t getCO2(std::vector<std::string> data) {
  for (int i = 0; i < data[0].size(); i++) {
    std::vector<std::string> one;
    std::vector<std::string> zero;
    for (auto &elem : data) {
      if (elem[i] == '1') {
        one.emplace_back(std::move(elem));
      } else {
        zero.emplace_back(std::move(elem));
      }
    }
    if (data.size() == 1) {
      break;
    } else if (zero.size() <= one.size()) {
      data = zero;
    } else {
      data = one;
    }
  }
  if (data.size() != 1) {
    throw std::runtime_error("Error! CO2 It should be only one left");
  }
  return std::stoi(data.front(), nullptr, 2);
}

int64_t getO2CO2(std::vector<std::string> data) {
  return getCO2(data) * getO2(data);
}