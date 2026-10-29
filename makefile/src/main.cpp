#include <iostream>
#include <vector>

#include "utils.hpp"

int main() {
    std::vector<int> numbers = {3, 7, 1, 9, 4};

    std::cout << "Suma: " << sum(numbers) << "\n";
    std::cout << "Srednia: " << average(numbers) << "\n";
    return 0;
}
