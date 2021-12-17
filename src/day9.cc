#include "day9.hpp"
#include "day4.hpp"
#include <algorithm>
#include <cctype>
#include <iterator>
#include <numeric>
#include <stdint.h>
#include <string>

std::vector<std::vector<short>> buildHeightMap(std::vector<std::string> data) {
  std::vector<std::vector<short>> heightMap;
  heightMap.resize(data.size());
  for (auto i = 0ull; i < data.size(); i++) {
    std::for_each(data[i].begin(), data[i].end(),
                  [&](char c) { heightMap[i].push_back(c - 48); });
  }
  return heightMap;
}
std::vector<short> getLowPoints(std::vector<std::vector<short>> heightMap) {
  std::vector<short> lowPoints;
  for (auto i = 0ull; i < heightMap.size(); i++) {
    for (auto j = 0ull; j < heightMap[i].size(); j++) {
      std::vector<short> adjacentPoints;
      if (i != 0) {
        adjacentPoints.push_back(heightMap[i - 1][j]);
      }
      if (j != 0) {
        adjacentPoints.push_back(heightMap[i][j - 1]);
      }
      if (i != heightMap.size() - 1) {
        adjacentPoints.push_back(heightMap[i + 1][j]);
      }
      if (j != heightMap[i].size() - 1) {
        adjacentPoints.push_back(heightMap[i][j + 1]);
      }
      adjacentPoints.push_back(heightMap[i][j]);
      short minElem = adjacentPoints.front();
      bool changed = false;
      for (auto &elem : adjacentPoints) {
        if (minElem > elem) {
          minElem = elem;
          changed = true;
        }
      }
      if (heightMap[i][j] == minElem && changed) {
        lowPoints.push_back(heightMap[i][j]);
      }
    }
  }
  return lowPoints;
}
int64_t calculateSumOfLowPoints(std::vector<short> lowPoints) {
  return std::accumulate(
      lowPoints.begin(), lowPoints.end(), 0ll,
      [](int64_t sum, short elem) { return sum + 1 + elem; });
}

int64_t getSumOfLowPoints(std::vector<std::string> data) {
  auto heightMap = buildHeightMap(data);
  auto lowPoints = getLowPoints(heightMap);
  return calculateSumOfLowPoints(lowPoints);
}