#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "ToyRT/layers.hpp"

class Network {
private:
    std::map<std::string, std::unique_ptr<Tensor>> tensors;
    std::map<std::string, std::unique_ptr<AbstractLayer>> layers;
    std::vector<std::string> input_names;
    std::vector<std::string> output_names;

    std::string make_tensor_name(std::string name, int index);

    Tensor* create_tensor(std::string name);

    template <typename LayerType>
    LayerType* create_layer(std::string name, const std::vector<Tensor*> inputs);

public:
    void print_network();

    Tensor* add_input(std::string name);

    void mark_output(Tensor* tensor);

    LinearLayer* add_linear(std::string name, Tensor* input);

    ReluLayer* add_relu(std::string name, Tensor* input);
};

