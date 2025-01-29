/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:46:59 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/14 01:08:39 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cerrno>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdlib.h>

void ScalarConverter::convert(const std::string &str) {
  if (str.empty()) {
    printImpossible();
    return;
  }
  if (str.size() == 1 && !std::isdigit(str[0])) {
    printConvertedResult(static_cast<double>(str[0]));
    return;
  }
  errno = 0;
  char *end;
  double value = strtod(str.c_str(), &end);
  if ((*end != '\0' && (*end != 'f' || *(end + 1) != '\0')) ||
      end == str.c_str() || errno != 0) {
    printImpossible();
    return;
  }
  printConvertedResult(value);
}

ScalarConverter::ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
  (void)other;
  return *this;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
  *this = other;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::toChar(double value) {
  if (std::isnan(value) || std::isinf(value) ||
      value < std::numeric_limits<char>::min() ||
      value > std::numeric_limits<char>::max()) {
    std::cout << "char: impossible\n";
    return;
  }
  char c = static_cast<char>(value);
  if (std::isprint(c)) {
    std::cout << "char: '" << c << "'\n";
  } else {
    std::cout << "char: Non displayable\n";
  }
}

void ScalarConverter::toInt(double value) {
  if (std::isnan(value) || std::isinf(value) ||
      value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max()) {
    std::cout << "int: impossible\n";
    return;
  }
  std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::toFloat(double value) {
  std::cout << "float: " << static_cast<float>(value) << "f\n";
}

void ScalarConverter::toDouble(double value) {
  std::cout << "double: " << value << std::endl;
}

void ScalarConverter::printImpossible() {
  std::cout << "char: impossible\n";
  std::cout << "int: impossible\n";
  std::cout << "float: impossible\n";
  std::cout << "double: impossible\n";
}

void ScalarConverter::printConvertedResult(double value) {
  std::cout << std::fixed << std::setprecision(1);
  toChar(value);
  toInt(value);
  toFloat(value);
  toDouble(value);
}
