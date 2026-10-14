#include <iostream>

int main(){
    try{
        // Code that may throw exception
        throw 505;
    }
    catch (int errorCode){
        std::cout << "Error occurred" << errorCode;
    }
    return 0;
}
