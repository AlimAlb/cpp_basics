#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>


int main(){
    std::unordered_set<int> freqs;
    std::string line;
    std::getline(std::cin, line);
    auto stream = std::istringstream(line);
    int num;
    while(stream >> num){
        auto [iter, flag] = freqs.insert(num);
        if(!flag){
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}
