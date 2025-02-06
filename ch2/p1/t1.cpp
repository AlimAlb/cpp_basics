#include <iostream>


template <typename T>
void Print(const T& container, std::string delim){
    auto iter = container.begin();
    std::cout << *(iter++);
    for (; iter != container.end(); ++iter)
    {
        std::cout << delim << *iter;
    }
    std::cout << '\n';
}

int main(){
    size_t n;
    std::cin >> n;
    std::vector<std::string> words;
    for (size_t i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        words.push_back(s);
    }

    Print<std::vector<std::string>>(words, ", ");
    
}