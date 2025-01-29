/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:11:03 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/14 02:17:51 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <string>

typedef struct Data {
  int no;
  std::string name;
} Data;

class Serializer {
public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

private:
  Serializer();
  Serializer(Serializer const &other);
  ~Serializer();

  Serializer &operator=(Serializer const &other);
};
#endif // SERIALIZER_HPP
