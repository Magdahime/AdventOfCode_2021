#include "day7.hpp"
#include "day4.hpp"
#include <algorithm>
#include <limits>
#include <math.h>
#include <numeric>
#include <stdint.h>

std::vector<int> getCrabPositions(std::vector<std::string> data) {
  auto parsedData = split(data.front(), ',');
  std::vector<int> crabPositions;
  std::transform(parsedData.begin(), parsedData.end(),
                 std::back_inserter(crabPositions),
                 [](std::string s) { return std::stoi(s); });
  return crabPositions;
}

double getAverage(const std::vector<int> &positions) {
  auto avg = std::accumulate(std::begin(positions), std::end(positions), 0.0) /
             std::size(positions);
  return avg;
}

int getMedian(std::vector<int> &positions) {
  std::sort(positions.begin(), positions.end());
  int median = positions[positions.size() / 2];
  return median;
}

int closest(std::vector<int> const &vec, double value) {
  auto closest = vec.begin();
  for (auto it = vec.begin(); it != vec.end(); it++) {
    if (fabs(*it - value) < fabs(*closest - value)) {
      closest = it;
    }
  }
  return *closest;
}

int64_t getFuelAmount(std::vector<std::string> data) {
  std::vector<int> crabPositions = getCrabPositions(data);
  int newPosition = getMedian(crabPositions);
  for (auto &crabPosition : crabPositions) {
    crabPosition = std::abs(crabPosition - newPosition);
    std::cout << crabPosition << std::endl;
  }
  return std::accumulate(crabPositions.begin(), crabPositions.end(), 0ll);
}

int64_t getNewFuelAmount(std::vector<std::string> data) {
  std::vector<int> crabPositions = getCrabPositions(data);
  int64_t result = std::numeric_limits<int64_t>::max();
  int min = (*std::min_element(crabPositions.begin(), crabPositions.end()));
  int max = (*std::max_element(crabPositions.begin(), crabPositions.end()));
  for (auto i = min; i < max; ++i) {
    auto partialResult =
        std::accumulate(crabPositions.begin(), crabPositions.end(), 0ll,
                        [i](int64_t curr_sum, int element) {
                          auto diff = std::abs(element - i);
                          auto calculated = (diff * (diff / 2.0 + 0.5));
                          return curr_sum + calculated;
                        });
    if (partialResult < result) {
      result = partialResult;
    }
  }
  return result;
}