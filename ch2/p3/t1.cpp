#include <iostream>
#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    std::vector<T> copy(v.size());
    std::copy(v.begin(), v.end(), copy.begin());
    for(auto& item: copy){
        v.push_back(item);
    }
}

int main(){
    std::vector<int> vec = {1,2,3,4,5};
    Duplicate(vec);
    for(auto& item: vec){
        std::cout << item << ' ';
    }
    std::cout << '\n';
}