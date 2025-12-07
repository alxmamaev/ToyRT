#pragma once

#include <memory>
#include <iostream>

#include "ToyRT/network.hpp"

class Builder {
private:
    std::unique_ptr<Network> network;

public:
    Builder();

    Network* create_network();

    void build();
};


