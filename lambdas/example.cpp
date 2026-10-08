#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    // Lambda function
    // [cc](p){fd};
    int d{7}, e{3};
    std::vector <int> v{2, 3, 7, 14, 23};
    std::for_each(v.begin(), v.end(), [](int x){std::cout << x << "\n";});

    std::for_each(v.begin(), v.end(), [](int x){
        if (x%2 == 0){
            std::cout <<x<<" is even number\n";
        }else{
            std::cout <<x<<" is odd number\n";
        }});

    std::for_each(v.begin(), v.end(), [d](int x){
        if (x%d == 0){
            std::cout <<x<<" is divisible by " << d << "\n";
        }else{
            std::cout <<x<<" is not divisible by " << d << "\n";
        }});

    std::for_each(v.begin(), v.end(), [&d, e](int x){

        if (x%d == 0){
            std::cout <<x<<" is divisible by " << d << "\n";
        }else{
            std::cout <<x<<" is not divisible by " << d << "\n";
            d=10;
            std::cout<<"d="<<d << " e=" << e << "\n";
        }});

    std::for_each(v.begin(), v.end(), [&](int x){

        if (x%d == 0){
            std::cout <<x<<" is divisible by " << d << "\n";
        }else{
            std::cout <<x<<" is not divisible by " << d << "\n";
            d=10;
            e=10;
            std::cout<<"d="<<d << " e=" << e << "\n";
        }});
        
    return 0;
}