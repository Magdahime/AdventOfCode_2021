#pragma once
#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

struct Point {
  int64_t x;
  int64_t y;
  Point(int64_t newX, int64_t newY) : x(newX), y(newY) {}
};

struct Line {
  Point start;
  Point end;
};

class Table {
public:
  Table(uint64_t x, uint64_t y)
      : table(x + 1, std::vector<uint64_t>(y + 1, 0)) {}

  void markNumber(Point p) { ++table[p.x][p.y]; }

  uint64_t getDangerousPoints() {
    uint64_t counter = 0;
    for (auto &row : table) {
      for (auto &elem : row) {
        if (elem >= 2) {
          counter++;
        }
      }
    }
    return counter;
  }

private:
  std::vector<std::vector<uint64_t>> table;
};

std::vector<Line> prepareLines(std::vector<std::string> data);
std::pair<int64_t, int64_t> getTableDims(std::vector<Line> lines);
uint64_t getDangerousZones(std::vector<std::string> data);
std::vector<std::string> splitString(const std::string &s, std::string delim);
void bresenhamAlgorithm(Table &table, std::vector<Line> lines);