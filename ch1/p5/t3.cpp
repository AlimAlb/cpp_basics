#include <iostream>
#include <vector>

std::vector<std::string> Split(const std::string& str, char delimiter){
    
    std::vector<std::string> words;
    std::string word;
    for (size_t i = 0; i < str.size(); i++)
    {   
        if (str[i] == delimiter){
            words.push_back(word);
            word.clear();
        } else {
            word.push_back(str[i]);
        }
    }
    words.push_back(word);
    
    return words;
}

int main(){
    std::string s;
    std::getline(std::cin, s);

    auto res = Split(s, '-');

    for (const auto& word : res)
    {
        std::cout << word << '\n';
    }
    
    
}
