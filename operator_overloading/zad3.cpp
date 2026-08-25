#include <iostream>

class Counter {
private:
    int value{0};
public:
    Counter(int value = 0) : value(value) {}
    Counter& operator++(){ // prefiks
        ++value;
        return *this;
    }
    Counter operator++(int) { // postfiks
        Counter temp = *this;
        ++value;
        return temp;
    }
    Counter& operator--(){ // prefiks
        --value;
        return *this;
    }
    Counter operator--(int){ //postfiks
        Counter temp = *this;
        --value;
        return temp;
    }
    auto print() const -> void {
        std::cout << value << std::endl;
    } 
};

int main() {
    Counter c;
    c++;
    c.print();
    return 0;
}