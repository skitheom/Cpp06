/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:47:05 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/13 20:06:02 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_CPP
#define SCALAR_CONVERTER_CPP

#include <string>

class ScalarConverter {
public:
  static void convert(const std::string &str);

private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &other);
  ~ScalarConverter();

  ScalarConverter &operator=(ScalarConverter const &other);

  static void toChar(double value);
  static void toInt(double value);
  static void toFloat(double value);
  static void toDouble(double value);

  static void printImpossible();
  static void printConvertedResult(double value);
};

#endif // SCALAR_CONVERTER_CPP
