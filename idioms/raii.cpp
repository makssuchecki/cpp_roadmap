#include <iostream>
#include <cstdio>
#include <utility>
#include <stdexcept>

// RAII (Resource Acquisition is Initialization) is a C++ idiom that ties the
// management of resources to the lifetime of objects.

// RAII classes 
// std::vector, std::string, std::unqiue_ptr, std::shared_ptr, std::lock_guard

class File {
    FILE* f_;   
public:
    explicit File(const char* path, const char* mode)
        : f_(fopen(path, mode)) {
        if (!f_) throw std::runtime_error("fopen failed");
    }

    ~File() { if (f_); }

    File(const File&) = delete;
    File& operator=(const File&) = delete;

    File(File&& other) noexcept : f_(std::exchange(other.f_, nullptr)) {}
    File& operator=(File&& other) noexcept{
        if (this != &other){
            if (f_) fclose(f_);
            f_ = std::exchange(other.f_, nullptr);
        }
        return *this;
    }
    FILE* get() const { return f_; }
};

void process(FILE* f){
    char buf[256];
    while (fgets(buf, sizeof buf, f)){
        std::fputs(buf, stdout);
    }
}
int main(){
    File f("data.txt", "r");
    process(f.get());
    return 0;
}