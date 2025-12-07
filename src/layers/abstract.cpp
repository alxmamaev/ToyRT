#include <string>
#include <vector>
#include <iostream>
#include "ToyRT/layers/abstract.hpp"

AbstractLayer::AbstractLayer(std::string name) {
    this->name = name;
}
void AbstractLayer::add_input(Tensor* input) {
    inputs.push_back(input);
}
void AbstractLayer::add_output(Tensor* output) {
    outputs.push_back(output);
}
std::string AbstractLayer::get_name() { return name; }
Tensor* AbstractLayer::get_output(int index) { return outputs[index]; }
Tensor* AbstractLayer::get_input(int index) { return inputs[index]; }