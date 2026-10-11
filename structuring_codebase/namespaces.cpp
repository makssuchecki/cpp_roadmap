#include <iostream>

// Namespace provides a solution for preventing name conflicts in large projects
// Each entity need a unique name. A namespace allows for identically named entities
// as long as namespaces are different

namespace first {
    int x = 1;
}
namespace second {
    int x = 2;
}
int main() {
    int x = 0;    

    std::cout << x << std::endl;
    std::cout << first::x << std::endl;
    std::cout << second::x << std::endl;

    return 0;
}