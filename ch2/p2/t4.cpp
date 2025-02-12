#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>

int main(){
    std::string s;
    size_t n;
    std::cin >> n;
    std::cin.ignore();
    std::map<int, std::set<std::string>> map;

    for (size_t i = 0; i < n; i++)
    {
        std::getline(std::cin, s);
        std::stringstream stream(s);
        std::string word;
        int page;
        stream >> word >> page;
        
        // если к странице уже существует множество - добавить слово в него
        // если нет - создать множество, добавить слово и положить в мап
        if(auto iter =  map.find(page); iter != map.end()){
            map[page].insert(word);
        } else {
            std::set<std::string> temp;
            temp.insert(word);
            map[page] = temp;
        }
    }
    // // std::sort(map.begin(), map.end(), [](const auto& p1, const auto& p2){
    // //     return p1.first < p2.first;
    // // });
    // std::vector<std::pair<int, std::unordered_set<std::string>>> vec(
    //     map.begin(),
    //     map.end()
    // );
    
    // std::sort(
    //     vec.begin(),
    //     vec.end(),
    //     [](const auto& p1, const auto& p2){
    //         return p1.first < p2.first;
    //     }
    // );
    for(auto& [page, set]: map){
        std::cout << page << ' ';
        for(auto& word: set){
            std::cout << word << ' ';
        }
        std::cout << '\n';
    }
    
}