#pragma once
#include <algorithm>
#include <iostream>
#include <array>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

template <size_t T> class BingoTable {
public:
  BingoTable(std::vector<std::string> data) {
    uint64_t counter = 0;
    for (auto i = 0ul; i < T; i++) {
      for (auto j = 0ul; j < T; j++) {
        uint64_t number = std::stoi(data[counter]);
        bingoTable.insert({number, {i, j}});
        numberOccurrence.insert({number, false});
        counter++;
      }
    }
    std::fill(std::begin(columnCounters), std::end(columnCounters), 0);
    std::fill(std::begin(rowCounters), std::end(rowCounters), 0);
  }

  bool checkBingo() {
    return std::find(columnCounters.begin(), columnCounters.end(), T) !=
               columnCounters.end() ||
           std::find(rowCounters.begin(), rowCounters.end(), T) !=
               rowCounters.end();
  }

  void markBingo(uint64_t number) {
    auto it = bingoTable.find(number);
    if (it != bingoTable.end()) {
      rowCounters[std::get<0>(it->second)]++;
      columnCounters[std::get<1>(it->second)]++;
      numberOccurrence[number] = true;
    }
  }

  std::vector<uint64_t> getBingoRow() {
    std::vector<uint64_t> bingoRow;
    auto rowIt = std::find(rowCounters.begin(), rowCounters.end(), T);
    if (rowIt != rowCounters.end()) {
      auto index = std::distance(rowCounters.begin(), rowIt);
      for (auto it = bingoTable.begin(); it != bingoTable.end(); ++it) {
        if (std::get<0>(it->second) == index) {
          bingoRow.push_back(it->first);
        }
      }

    } else {
      auto columnIt =
          std::find(columnCounters.begin(), columnCounters.end(), T);
      if (columnIt != columnCounters.end()) {
        auto index = std::distance(columnCounters.begin(), columnIt);
        for (auto it = bingoTable.begin(); it != bingoTable.end(); ++it) {
          if (std::get<1>(it->second) == index) {
            bingoRow.push_back(it->first);
          }
        }
      }
    }
    return bingoRow;
  }

  std::vector<uint64_t> getUnmarked() {
    std::vector<uint64_t> unmarked;
    for (auto it = numberOccurrence.begin(); it != numberOccurrence.end();
         ++it) {
      if (it->second == false) {
        unmarked.push_back(it->first);
      }
    }
    return unmarked;
  }

private:
  std::array<uint64_t, T> columnCounters;
  std::array<uint64_t, T> rowCounters;
  std::map<uint64_t, std::pair<uint64_t, uint64_t>> bingoTable;
  std::map<uint64_t, bool> numberOccurrence;
};

std::vector<std::string> split(const std::string &s, char delim);
std::vector<BingoTable<5>> prepareBingoTables(std::vector<std::string> data);
uint64_t getBestBingoTable(std::vector<std::string> data);
uint64_t getWorstBingoTable(std::vector<std::string> data);