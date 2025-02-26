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
  const int kObjSize = 7;
  Base *obj;
  for (size_t i = 0; i < kObjSize; ++i) {
    obj = generate();
    if (!obj) {
      std::cout << "Failed to generate A/B/C object." << std::endl;
      return 1;
    }
    std::cout << "\n--- object No." << i << " ---" << std::endl;
    std::cout << "Identify as ptr: ";
    identify(obj);
    std::cout << "Identify as ref: ";
    identify(*obj);
    delete obj;
  }
  return 0;
}
