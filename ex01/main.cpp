/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:18:07 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/14 02:26:59 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main(void) {

  Data sample;
  sample.no = 101;
  sample.name = "Pham";

  uintptr_t raw = Serializer::serialize(&sample);
  Data *result = Serializer::deserialize(raw);

  std::cout << "Before Serialization\n\tNo: " << sample.no
            << "\n\tName: " << sample.name << std::endl;
  std::cout << "uintptr_t raw = " << raw << std::endl;
  std::cout << "After Serialization\n\tNo: " << result->no
            << "\n\tName: " << result->name << std::endl;
  return 0;
}
