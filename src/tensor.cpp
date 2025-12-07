#include <string>
#include <iostream>
#include "ToyRT/tensor.hpp"

Tensor::Tensor(std::string name) {
    this->name = name;
}

std::string Tensor::get_name() { return name; }

std::ostream& operator<<(std::ostream& os, const Tensor& tensor) {
    os << "Tensor(" << tensor.name << ")";
    return os;
}