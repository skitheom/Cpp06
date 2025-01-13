/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:20:48 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/13 20:05:28 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, const char *argv[]) {

  if (argc != 2) {
    std::cerr << "[Usage] ./convert <input>" << std::endl;
    return 1;
  }
  ScalarConverter::convert(std::string(argv[1]));
  return 0;
}
