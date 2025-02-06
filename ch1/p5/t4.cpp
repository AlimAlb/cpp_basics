#include <vector>
#include <iostream>

std::string Join(const std::vector<std::string>& tokens, char delimiter){
    std::string joined;
    if(tokens.size() == 0){
        return "";
    } else {
        joined = tokens[0];
    }

    for (size_t i = 1; i != tokens.size(); i++)
    {
        joined.push_back(delimiter);
        joined.append(tokens[i]);
    }

    return joined;
    
}

int main(){
    std::vector<std::string> tokens;
    int n;
    char delimiter;
    std::cin >> n;
    std::cin >> delimiter;
    std::cin.ignore();
    
    
    for (size_t i = 0; i < n; i++)
    {
        std::string s;
        std::getline(std::cin, s);
        tokens.push_back(s);
    }

    std::string res = Join(tokens, delimiter);
    std::cout << '\n' << res << '\n';
    
}