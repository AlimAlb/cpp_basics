#include <iostream>
#include <unordered_map>
#include <algorithm>

int main(){
    std::string s;
    std::unordered_map<char, int> syms;
    int words = 0;
    while(std::cin >> s){
        words++;
        std::unordered_map<char, int> word;
        for(char sym: s){
            if(word[sym] == 0){
                word[sym]++;
            }
        }
        for(const auto& [sym, num] : word){
            syms[sym] += num;
            
        }
        
    }
    std::string out;
    for(const auto& [sym, num]: syms){
        if(num == words){
            out.push_back(sym);
        }
    }
    std::sort(out.begin(), out.end());
    std::cout << out << '\n';
}
