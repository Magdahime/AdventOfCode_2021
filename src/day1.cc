#include "day1.hpp"
#include <stdint.h>
#include <stdlib.h>
#include <string>

std::vector<std::string> loadDataFromFile(std::string filename) {
  std::vector<std::string> data;
  std::fstream file(filename);
  std::string line;
  if (file.is_open()) {
    while (std::getline(file, line)) {
      data.push_back(line);
    }
  } else {
    throw std::runtime_error("Error cannot open file!");
  }
  return data;
}

std::vector<int64_t> convertStringVector(std::vector<std::string> data){
  std::vector<int64_t> newData;
  for(auto elem: data){
    newData.push_back(std::stoi(elem));
  }
  return newData;
}