#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::vector<std::string> vec;
    std::string s;
    
    while(std::getline(std::cin, s)){
        vec.push_back(s);
    }


    std::sort(vec.rbegin(), vec.rend());

    for (size_t i = 0; i != vec.size(); i++)
    {
        std::cout << vec[i] << '\n';
    }

}