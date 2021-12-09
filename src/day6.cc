#include "day6.hpp"
#include "day4.hpp"
#include <algorithm>
#include <iterator>
#include <numeric>
#include <stdint.h>
#include <string>

std::vector<int8_t> prepareFishColony(std::vector<std::string> data) {
  auto parsedData = split(data.front(), ',');
  std::vector<int8_t> fishColony;
  std::transform(parsedData.begin(), parsedData.end(),
                 std::back_inserter(fishColony),
                 [](std::string s) { return std::stoi(s); });
  return fishColony;
}

void calculateDay(std::vector<int8_t> &fishColony) {
  uint64_t colonySize = fishColony.size();
  for (auto i = 0ul; i < colonySize; i++) {
    if (fishColony[i] != 0) {
      fishColony[i]--;
    } else {
      fishColony[i] = 6;
      fishColony.push_back(8);
    }
  }
}

uint64_t getNumberOfFishesTrivial(std::vector<std::string> data,
                                  uint64_t days) {
  std::vector<int8_t> fishColony = prepareFishColony(data);
  for (auto i = 0ul; i < days; i++) {
    calculateDay(fishColony);
  }
  return fishColony.size();
}

uint64_t getNumberOfFishes(std::vector<std::string> data, uint64_t days) {
  std::vector<int8_t> fishColony = prepareFishColony(data);
  std::vector<uint64_t> fishMapping(9, 0);
  for (auto &fish : fishColony) {
    fishMapping[fish]++;
  }
  for (auto i = 0ul; i < days; i++) {
    iterate(fishMapping);
  }

  return std::accumulate(fishMapping.begin(), fishMapping.end(), 0ull);
}

void iterate(std::vector<uint64_t> &fishMapping) {
  uint64_t zeroDaysFishes = fishMapping[0];
  for (auto i = 1ul; i < fishMapping.size(); i++) {
    fishMapping[i - 1] = fishMapping[i];
    fishMapping[i] = 0;
  }
  fishMapping[6] += zeroDaysFishes;
  fishMapping[8] += zeroDaysFishes;
}
