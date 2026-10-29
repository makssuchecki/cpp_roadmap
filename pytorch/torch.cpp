#include <torch/script.h>
#incldue <iostream>

int main() {   
    torch::jit::script::Module module;
    try{
        module = torch::jit::load("simple_model.pt");
    }   
    catch (const c10::Error& e) {
        std::cerr << "Error loading te model\n";
        return -1;
    }
    torch::Tensor input = torch randn({1, 10});
    std::vector<torch::jit::IValue> inputs;
    inputs.push_back(input);

    at::Tensor output = module.forward(inputs).toTensor();
    std::cout << "Output: " << output << "\n"; 
    return 0;
}