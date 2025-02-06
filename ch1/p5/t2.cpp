#include <iostream>
#include <utility>
#include <vector>
#include <limits>


std::string CommonPrefix(const std::vector<std::string>& words){
    size_t minLength = std::numeric_limits<int>::max();
    std::string prefix;
    if (words.size() == 0){
        return prefix;
    }
    
    for (size_t i = 0; i != words.size(); i++)
    {
        if (words[i].size() < minLength){
            minLength = words[i].size();
        }    
    }

    for (size_t i = 0; i != minLength; i++)
    {
        size_t sum = 0;
        for (size_t j = 0; j < words.size()-1; j++)
        {
            sum += (words[j][i] == words[j+1][i]);
        }
        if (sum == words.size()-1){
            prefix.push_back(words[0][i]);
        }
        
    }
    
    return prefix;
}

int main(){
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<std::string> s;
    for (size_t i = 0; i < n; i++)
    {
        std::string word;
        std::getline(std::cin, word);
        s.push_back(word);
    }

    std::string res = CommonPrefix(s);

    std::cout << res << '\n';
    
}