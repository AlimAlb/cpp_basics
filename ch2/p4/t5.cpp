#include <string_view>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <utility>


int main(){
    std::string line;
    size_t number;
    std::cin >> number;
    std::cin.ignore();
    std::unordered_map<std::string, int> map;
    
    while(std::getline(std::cin, line) && line != "end"){
        std::stringstream ss(line);
        std::string word;
        while(ss >> word){
            ++map[word];
        }
    }

    std::vector<std::pair<std::string, int>> vec(map.begin(), map.end());
    auto offset = vec.begin() + number;
    if(number >= vec.size()){
        offset = vec.end();
    }
    std::partial_sort(
        vec.begin(),
        offset,
        vec.end(),
        [](auto& pr1, auto& pr2){
            if(pr1.second > pr2.second){
                return true;
            } else if(pr1.second == pr2.second){
                return pr1.first < pr2.first;
            } else {
                return false;
            }
        }
    );
    for(auto& [word, num]: vec){
        if(!number){
            break;
        }
        std::cout << word << '\t' << num << '\n';
        number--;
    }

}