#include "ToyRT/network.hpp"

std::string Network::make_tensor_name(std::string name, int index) {
    return name + "_" + std::to_string(index);
}

Tensor* Network::create_tensor(std::string name) {
    if (tensors.find(name) != tensors.end()) {
        throw std::runtime_error("Tensor with name " + name + " already exists");
    }

    std::unique_ptr<Tensor> tensor = std::make_unique<Tensor>(name);
    auto tensor_ptr = tensor.get();
    tensors[name] = std::move(tensor);
    return tensor_ptr;
}

template <typename LayerType>
LayerType* Network::create_layer(std::string name, const std::vector<Tensor*> inputs) {
    if (layers.find(name) != layers.end()) {
        throw std::runtime_error("Layer with name " + name + " already exists");
    }

    std::unique_ptr<LayerType> layer = std::make_unique<LayerType>(name);
    for (Tensor* input : inputs) {
        layer->add_input(input);
    }
    for (int i = 0; i < static_cast<int>(layer->get_num_outputs()); i++) {
        Tensor* output = create_tensor(make_tensor_name(name, i));
        layer->add_output(output);
    }

    LayerType* layer_ptr = layer.get();
    layers[name] = std::move(layer);
    return layer_ptr;
}

void Network::print_network() {
    auto print_vector = [](std::vector<std::string> vector) {
        if (vector.size() == 0) {
            std::cout << "not initialized" << std::endl;
            return;
        } else {
            for (size_t i = 0; i < vector.size() - 1; i++) {
                std::cout << vector[i] << ", ";
            }
            std::cout << vector[vector.size() - 1] << std::endl;
        }
    };

    std::cout << "INPUTS: ";
    print_vector(input_names);

    std::cout << "OUTPUTS: ";
    print_vector(output_names);

    std::cout << std::endl << "LAYERS: " << std::endl;
    for (auto& layer : layers) {
        std::cout << layer.second->get_name() << std::endl;
    }
}

Tensor* Network::add_input(std::string name) {
    Tensor* tensor_ptr = create_tensor(name);
    input_names.push_back(name);
    return tensor_ptr;
}

void Network::mark_output(Tensor* tensor) {
    if (tensors.find(tensor->get_name()) == tensors.end()) {
        throw std::runtime_error("Tensor with name " + tensor->get_name() + " not found");
    }

    if (tensors[tensor->get_name()].get() != tensor) {
        throw std::runtime_error("Passed tensor is not part of network");
    }

    if (std::find(output_names.begin(), output_names.end(), tensor->get_name()) != output_names.end()) {
        throw std::runtime_error("Tensor with name " + tensor->get_name() + " already marked as output");
    }

    output_names.push_back(tensor->get_name());
}

LinearLayer* Network::add_linear(std::string name, Tensor* input) {
    LinearLayer* layer = create_layer<LinearLayer>(name, {input});
    return layer;
}

ReluLayer* Network::add_relu(std::string name, Tensor* input) {
    ReluLayer* layer = create_layer<ReluLayer>(name, {input});
    return layer;
}

