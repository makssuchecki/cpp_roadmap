#include <iostream>
#include <memory>
#include <string>

// Copy on write is an optimization technique used to defer or eliminate the cost
// of copying resources until the first write operation

class CowString{
    std::shared_ptr<std::string> data_;

    void detach(){
        if (data_.use_count() > 1){
            data_ = std::make_shared<std::string>(*data_);
        }
    }
public:
    explicit CowString(std::string s)
        : data_(std::make_shared<std::string>(std::move(s))) {}
    CowString(const CowString&) = default;
    CowString& operator=(const CowString&) = default;

    char operator[](std::size_t i) const { return (*data_)[i]; }
    const std::string& str() const { return *data_; }

    void set(std::size_t i, char c){
        detach();
        (*data_)[i] = c;
    }
    void append(const std::string& s){
        detach();
        data_->append(s);
    }
};

int main(){
    CowString a("Hello");
    CowString b = a;
    b.set(0, 'J');
    std::cout << a.str() << " " << b.str() << "\n";
    return 0;
}