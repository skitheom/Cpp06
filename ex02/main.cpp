/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:40:52 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/14 14:20:13 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "util.hpp"
#include <iostream>

int main(void) {
  static const int kObjSize = 5;
  Base *obj[kObjSize];
  for (size_t i = 0; i < kObjSize; i++) {
    obj[i] = generate();
    if (!obj[i]) {
      std::cout << "Failed to generate A/B/C object." << std::endl;
      continue;
    }
    std::cout << "--- obj[" << i << "] ---" << std::endl;
    std::cout << "Identify as ptr: ";
    identify(obj[i]);
    std::cout << "Identify as ref: ";
    identify(*obj[i]);
    delete obj[i];
  }
  return 0;
}
