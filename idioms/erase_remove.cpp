#include <iostream>
#include <vector>
#include <algorithm>


int main(){
    std::vector<int> v{1, 2, 3, 4, 5, 6};

    auto newEnd = std::remove(v.begin(), v.end(), 2);

    v.erase(newEnd, v.end());
    return 0;
};
