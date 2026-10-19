#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

// Vectors are dynamic arrays that can resize themselves as needed.
// They store elements in a contiguous memory location, allowing
// fast random access using indices

void vectors() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);

    std::cout << "Vector contains: ";
    for (int x : vec) 
    {
        std::cout<< ' ' << x;
    }
    std::cout << '\n';
}

// List is a doubly-linked list that allows elements to be inserted or removed
// from any position in constant time. It does not support random access.
// Lists are better than vectors for scenarios where you need to insert or remove elements
// in the middle frequently

void lists(){
    std::list<int> lst = {1, 2, 3, 4, 5};

    lst.push_back(6);
    std::cout << "List contains:";
    for (int x : lst)
    {
        std::cout << " " << x;
    }
    std::cout << '\n';
}

// Map is an associative container that stores key-value pairs. It supports the retrieval of values
// based on their keys. The keys are sorted in ascending order by default
void maps(){
    std::map<std::string, int> m;

    m["one"] = 1;
    m["two"] = 2;

    std::cout << "Map contains: \n";
    for (const auto &pair : m){
        std::cout << pair.first << ": " << pair.second << '\n';
    }
}

// Unordered map stores key-value pairs, but it is implemented using a hash table.
// This means unordered_map has faster average-case performance compared to map, since it does not maintain
// sorted order. However worst-case performance can be worse than map

void unordered_maps(){
    std::unordered_map<std::string, int> um;

    um["one"] = 1;
    um["two"] = 2;

    std::cout << "Unordered map contains:\n";
    for (const auto &pair : um)
    {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

int main(){
    vectors();
    lists();
    maps();
    unordered_maps();
    return 0;
}