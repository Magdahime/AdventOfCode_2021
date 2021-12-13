#include "day8.hpp"
#include "day4.hpp"
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdint.h>
#include <string>

int64_t countStrings(std::vector<std::string> data,
                     std::vector<int64_t> sizes) {
  return std::count_if(data.begin(), data.end(), [&](std::string s) {
    return std::find(sizes.begin(), sizes.end(), s.size()) != sizes.end();
  });
}

std::pair<std::vector<std::string>, std::vector<std::string>>
prepareDigitInput(std::vector<std::string> data) {
  std::vector<std::string> digits;
  std::vector<std::string> digitInput;
  for (auto &elem : data) {
    auto splittedRow = split(elem, '|');
    auto digitsTmp = split(splittedRow[0], ' ');
    for (auto &digit : digitsTmp) {
      digit.erase(remove_if(digit.begin(), digit.end(), isspace), digit.end());
    }
    std::copy_if(digitsTmp.begin(), digitsTmp.end(), std::back_inserter(digits),
                 [](const std::string &s) { return !s.empty(); });
    auto digitInputTmp = split(splittedRow[1], ' ');
    for (auto &digit : digitInputTmp) {
      digit.erase(remove_if(digit.begin(), digit.end(), isspace),
                  digit.end());
    }
    std::copy_if(digitInputTmp.begin(), digitInputTmp.end(),
                 std::back_inserter(digitInput),
                 [](const std::string &s) { return !s.empty(); });
  }
  return {digits, digitInput};
}

int64_t countSimplestDigits(std::vector<std::string> data) {
  auto digitInput = prepareDigitInput(data);
  std::vector<int64_t> sizes{2, 3, 4, 7};
  return countStrings(digitInput.second, sizes);
}

std::map<int, std::string> prepareDigitMap(std::vector<std::string> data) {
  std::map<int, std::string> mapping;
  for (auto &elem : data) {
    if (elem.length() == 2 || elem.length() == 3 || elem.length() == 4 ||
        elem.length() == 7) {
      mapping.insert({elem.length(), elem});
    }
  }
  return mapping;
}

int64_t getSumOfDigits(
    std::pair<std::vector<std::string>, std::vector<std::string>> data) {
  std::vector<std::string> &digits = data.first;
  std::vector<std::string> &digitInput = data.second;
  std::stringstream ss;
  int64_t counter = 0;
  auto it = digits.begin();
  auto itInput = digitInput.begin();
  while (it != digits.end()) {
    auto mapping = prepareDigitMap(std::vector<std::string>(it, it + 10));
    for (int i = 0; i < 4; i++) {
      std::string elem = *(itInput + i);
      switch (elem.size()) {
      case 2:
        ss << "1";
        break;
      case 3:
        ss << "7";
        break;
      case 4:
        ss << "4";
        break;
      case 7:
        ss << "8";
        break;
      case 5:
        if (getCommonChars(elem, mapping[2]) == 2) {
          ss << "3";
        } else if (getCommonChars(elem, mapping[4]) == 3) {
          ss << "5";
        } else {
          ss << "2";
        }
        break;
      case 6:
        if (getCommonChars(elem, mapping[2]) == 1) {
          ss << "6";
        } else if (getCommonChars(elem, mapping[4]) == 3) {
          ss << "0";
        } else {
          ss << "9";
        }
        break;
      default:
        break;
      }
    }
    counter += std::stoi(ss.str());
    ss.str(std::string());
    it += 10;
    itInput += 4;
  }
  return counter;
}

int64_t countDigits(std::vector<std::string> data) {
  auto digitInput = prepareDigitInput(data);
  return getSumOfDigits(digitInput);
}

int getCommonChars(std::string s1, std::string s2) {
  std::map<char, int> s1Map;
  std::map<char, int> s2Map;
  int64_t counter = 0;
  for (auto &elem : s1) {
    s1Map[elem]++;
  }
  for (auto &elem : s2) {
    s2Map[elem]++;
  }
  for (auto const &elem : s1Map) {
    counter += std::min(s1Map[elem.first], s2Map[elem.first]);
  }
  return counter;
}