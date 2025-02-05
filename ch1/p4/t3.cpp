#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>

bool compare(std::pair<int, int> a, std::pair<int, int> b){
    return a.first < b.first;
}

int main(){

    std::string line;
    std::vector<std::pair<int, int>> pairs;
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::getline(std::cin, line);
    std::istringstream iss(line); // Создаем поток из строки
    
    int num;
    int idx = 1;
    while (iss >> num) { // Считываем числа из потока
        pairs.push_back(std::pair<int, int>(num, idx++));
    }

    std::sort(pairs.begin(), pairs.end(), compare);

    
    for (size_t i = 0; i != pairs.size(); i++)
    {
        std::cout << pairs[i].second << ' ';
    }
    std::cout << '\n';
    


    
    
}
