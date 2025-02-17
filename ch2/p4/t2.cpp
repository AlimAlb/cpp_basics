#include <set>
#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec;
    size_t window_size, n;
    std::cin >> n >> window_size;
    std::multiset<int> window;
    int curr;
    while(n > 0){
        n--;
        std::cin >> curr;
        vec.push_back(curr);
    }
    if(window_size >= vec.size()){
        std::cout << *std::min(vec.begin(), vec.end()) << '\n';

    } else if(!vec.empty()){
        std::copy(vec.begin(), vec.begin() + window_size, std::inserter(window, window.begin()));
        vec.push_back(0);
        auto prev = vec.begin();
        auto iter = vec.begin() + window_size;
        for(; iter != vec.end(); ++iter){
            std::cout << *window.begin() << '\n';
            auto er = window.find(*prev);
            window.erase(er);
            window.insert(*iter);
            ++prev;    
        }
    }
} // erase удаляет все вхождения элемента - подобрать тест на котором WA
