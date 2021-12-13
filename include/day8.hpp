#pragma once

#include <map>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

int64_t countStrings(std::vector<std::string> data, std::vector<int64_t> sizes);
std::pair<std::vector<std::string>, std::vector<std::string>>
prepareDigitInput(std::vector<std::string> data);
int64_t countSimplestDigits(std::vector<std::string> data);
int64_t getSumOfDigits(
    std::pair<std::vector<std::string>, std::vector<std::string>>);
int64_t countDigits(std::vector<std::string> data);
std::map<int, std::string> prepareDigitMap(std::vector<std::string> data);
int getCommonChars(std::string s1, std::string s2);
