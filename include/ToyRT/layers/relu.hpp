#pragma once
#include "ToyRT/layers/abstract.hpp"

class ReluLayer : public AbstractLayer {
    public:
    ReluLayer(std::string name) : AbstractLayer(name) {}
    size_t get_num_outputs();
};