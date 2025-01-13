/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:46:59 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/13 20:05:14 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
  *this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
  (void)other;
  return *this;
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

void ScalarConverter::convert(const std::string &str) {
  if (str.empty()) {
    printImpossible();
    return;
  }
  if (str.length() == 1 && !std::isdigit(str.front())) {
    printConvertedResult(static_cast<double>(str.front()));
    return;
  }
  double value = 0;

  try {
    size_t pos = 0;
    value = std::stod(str, &pos);
    if (pos < str.size() && (pos + 1 != str.size() || str.at(pos) != 'f')) {
      printImpossible();
      return;
    }
  } catch (std::exception &e) {
    printImpossible();
    return;
  }
  printConvertedResult(value);
}
