#include <iostream>
#include <list>

int main(){
    std::list<int> lst = {1,2,3,4,5};
    auto iter = lst.begin();
    auto tmp = lst.begin();
    //std::advance(iter, 1);
    std::list<int> buff;
    buff.splice(buff.begin(), lst, tmp, iter);
    for(auto i : buff){
        std::cout << i << ' ';
    };
    std::cout << '\n';
}