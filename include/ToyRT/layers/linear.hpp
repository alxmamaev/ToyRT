#pragma once
#include "ToyRT/layers/abstract.hpp"

class LinearLayer : public AbstractLayer {
    public:
        LinearLayer(std::string name) : AbstractLayer(name) {}
        size_t get_num_outputs();
    };