#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>


#include "day1.hpp"
#include "day2.hpp"
#include "day3.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    return EXIT_FAILURE;
  }

  std::vector<std::string> elements = loadDataFromFile(argv[1]);
  // std::cout<<countIncrease(convertStringVector(elements),3) << "\n";
  //std::cout << getDirections(elements) << "\n";
  //std::cout << getGammaEpsilon(elements) << "\n";
  std::cout << getO2CO2(elements) << "\n";
}