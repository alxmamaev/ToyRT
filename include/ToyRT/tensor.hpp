#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Tensor {
private:
    std::string name;
public:
    Tensor(std::string name);
    std::string get_name();
    friend std::ostream& operator<<(std::ostream& os, const Tensor& tensor);
};