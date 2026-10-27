#include <iostream>

class File {
    FILE* f;
public:
    explicit File(const char* p) : f(fopen(p, "r")) {}
    ~File() { if (f) fclose(f); }

    File(const File&)            = delete;  
    File& operator=(const File&) = delete;

    File(File&&)                 = delete; 
    File& operator=(File&&)      = delete;
};

int main(){
    File a("x.txt");
    // File b = a;             compile error
    // File c = std::move(a);  compile error
    return 0;
}
