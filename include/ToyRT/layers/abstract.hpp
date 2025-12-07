#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "ToyRT/tensor.hpp"

class AbstractLayer {
private:
    std::string name;
    std::vector<Tensor*> inputs;
    std::vector<Tensor*> outputs;    
public:
    AbstractLayer(std::string name);
    void add_input(Tensor* input);
    void add_output(Tensor* output);

    std::string get_name();
    Tensor* get_output(int index);
    Tensor* get_input(int index);

    friend std::ostream& operator<<(std::ostream& os, const AbstractLayer& layer);
    virtual size_t get_num_outputs() = 0;
};
