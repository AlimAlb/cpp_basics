#include <vector>
#include <iostream>
#include <list>

template <typename Iter>
Iter Unique(Iter first, Iter last){
    if(first == last){
        return last;
    }
    auto write = first;
    auto read = first;
    read++;
    while(read != last){
        if(*write != *read){
            *(++write) = *read;
        }
        read++;
    }
    return ++write;
}


int main(){
    std::vector<int> vec = {2,2,2,3,2,2,5,2,4,5,6};
    auto iter = Unique(vec.begin(), vec.end());
    for(auto& item: vec){
        std::cout << item << ' ';
    }
    std::cout << '\n';
    std::cout << "end of seq: ";
    for(; iter!= vec.end(); ++iter){
        std::cout << *iter << ' ';
    }
    std::cout << '\n';
}   