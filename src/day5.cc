#include "day5.hpp"
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <stdint.h>
#include <string>

std::vector<std::string> splitString(const std::string &s, std::string delim) {
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;

  while (getline(ss, item, delim.front())) {
    result.push_back(item);
    ss.ignore(delim.size() - 1);
  }
  return result;
}

std::vector<Line> prepareLines(std::vector<std::string> data) {
  std::vector<Line> parsedLines;
  for (auto &elem : data) {
    std::vector<std::string> splitted = splitString(elem, "->");
    auto it = splitted.begin();
    while (it != splitted.end()) {
      std::vector<std::string> startNumbers = splitString(*it, ",");
      std::vector<std::string> endNumbers = splitString(*(it + 1), ",");
      std::copy(endNumbers.begin(), endNumbers.end(),
                std::back_inserter(startNumbers));
      if (startNumbers.size() != 4) {
        throw std::runtime_error("Error in data - more than 2 points defined");
      }
      parsedLines.push_back(
          Line{Point{std::stoi(startNumbers[0]), std::stoi(startNumbers[1])},
               Point{std::stoi(startNumbers[2]), std::stoi(startNumbers[3])}});
      it = it + 2;
    }
  }
  return parsedLines;
}

std::pair<int64_t, int64_t> getTableDims(std::vector<Line> lines) {
  int64_t xMax = 0;
  int64_t yMax = 0;
  for (auto &line : lines) {
    xMax = std::max({xMax, line.start.x, line.end.x});
    yMax = std::max({yMax, line.start.y, line.end.y});
  }
  return {xMax, yMax};
}

uint64_t getDangerousZones(std::vector<std::string> data) {
  std::vector<Line> lines = prepareLines(data);
  auto dimensions = getTableDims(lines);
  Table table(dimensions.first, dimensions.second);
  bresenhamAlgorithm(table, lines);
  return table.getDangerousPoints();
}

void bresenhamAlgorithm(Table &table, std::vector<Line> lines) {
  for (auto &line : lines) {

    auto signum = [](int64_t value) { return (value > 0) - (value < 0); };
    int8_t sigX = signum(line.end.x - line.start.x);
    int8_t sigY = signum(line.end.y - line.start.y);
    auto lenX = std::abs(line.start.x - line.end.x);
    auto lenY = std::abs(line.start.y - line.end.y);
    if (lenX == 0 || lenY == 0 || (lenX == lenY)) {
      for (int i = 0; i <= std::max(lenX, lenY); i++) {
        table.markNumber({line.start.x + i * sigX, line.start.y + i * sigY});
      }
    }
  }
}