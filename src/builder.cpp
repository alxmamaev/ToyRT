#include "ToyRT/builder.hpp"

Builder::Builder() = default;

Network* Builder::create_network() {
    network = std::make_unique<Network>();
    return network.get();
}

void Builder::build() {
    // DUMMY FOR NOW
    std::cout << "Building network..." << std::endl;
    network->print_network();
}


