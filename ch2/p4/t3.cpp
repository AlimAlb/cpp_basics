#include <iostream>
#include <queue>
#include <sstream>

int main(){
    std::priority_queue<int> pq;
    std::string s;
    while(std::getline(std::cin, s)){
        std::stringstream ss(s);
        std::string operation;
        int number;
        ss >> operation >> number;
        if(operation == "ADD"){
            pq.push(number);

        } else if(operation == "EXTRACT"){
            if(!pq.empty()){
                std::cout << pq.top() << '\n';
                pq.pop();
            } else {
                std::cout << "CANNOT\n";
            }

        } else if(operation == "CLEAR"){
            pq = std::priority_queue<int>();
        }
    }
}