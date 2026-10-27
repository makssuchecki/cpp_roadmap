#include "utils.hpp"

#include <numeric>

int sum(const std::vector<int>& v){
    return std::accumulate(v.begin(), v.end(), 0);
}

double average(const std::vector<int>& v){
    if (v.empty()) return 0.0;
    return static_cast<double>(sum(v)) / v.size();
}
