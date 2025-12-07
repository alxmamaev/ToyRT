#include "ToyRT/builder.hpp"

int main() {
    Builder builder;
    Network* network = builder.create_network();

    Tensor* input = network->add_input("MODEL_INPUT");
    LinearLayer* linear_1 = network->add_linear("linear_1", input);
    ReluLayer* relu_1 = network->add_relu("relu_1", linear_1->get_output(0));
    LinearLayer* linear_2 = network->add_linear("linear_2", linear_1->get_output(0));
    ReluLayer* relu_2 = network->add_relu("relu_2", linear_2->get_output(0));

    network->mark_output(relu_2->get_output(0));
    
    builder.build();

    return 0;
}