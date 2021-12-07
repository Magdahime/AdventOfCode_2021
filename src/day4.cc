#include "day4.hpp"
#include <cctype>
#include <iostream>
#include <iterator>
#include <numeric>
#include <stdint.h>

std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }

  return result;
}

std::vector<BingoTable<5>> prepareBingoTables(std::vector<std::string> data) {
  std::vector<BingoTable<5>> bingoTables;
  std::vector<std::string> oneBingoTable;
  for (auto &elem : data) {
    if (elem.empty()) {
      if (!oneBingoTable.empty())
        bingoTables.push_back(BingoTable<5>(oneBingoTable));
      oneBingoTable.clear();
    }
    auto splittedRow = split(elem, ' ');
    std::copy_if(splittedRow.begin(), splittedRow.end(),
                 std::back_inserter(oneBingoTable),
                 [](std::string s) { return !s.empty(); });
  }
  return bingoTables;
}

uint64_t getBestBingoTable(std::vector<std::string> data) {

  std::vector<std::string> bingoNumbers = split(data.front(), ',');
  data.erase(data.begin());
  std::vector<BingoTable<5>> bingoTables = prepareBingoTables(data);
  for (auto &number : bingoNumbers) {
    for (auto &table : bingoTables) {
      uint64_t numberInt = std::stoi(number);
      table.markBingo(numberInt);
      if (table.checkBingo()) {
        std::vector<uint64_t> unmarked = table.getUnmarked();
        return std::accumulate(unmarked.begin(), unmarked.end(), 0) * numberInt;
      }
    }
  }
  return 0;
}

uint64_t getWorstBingoTable(std::vector<std::string> data) {
  std::vector<std::string> bingoNumbers = split(data.front(), ',');
  data.erase(data.begin());
  std::vector<BingoTable<5>> bingoTables = prepareBingoTables(data);
  for (auto &number : bingoNumbers) {
    uint64_t numberInt = std::stoi(number);
    auto it = bingoTables.begin();
    while (it != bingoTables.end()) {
      uint64_t endValue = 0;
      it->markBingo(numberInt);
      if (it->checkBingo()) {
        std::vector<uint64_t> unmarked = it->getUnmarked();
        endValue =
            std::accumulate(unmarked.begin(), unmarked.end(), 0) * numberInt;
        it = bingoTables.erase(it);
        if (bingoTables.empty()) {
          return endValue;
        }
        continue;
      }
      ++it;
    }
  }
  return 0;
}
