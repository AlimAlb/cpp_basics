#include <iostream>
#include <deque>
#include <vector>


std::vector<std::string> split(std::string s){
    std::string s1, s2;
    size_t idx = 0;
    while (s[idx] != ' '){
        s1.push_back(s[idx]);
        idx++;
    }
    idx ++;
    while(idx < s.size()){
        s2.push_back(s[idx]);
        idx++;
    }
    std::vector<std::string> ret = {s1, s2};
    return ret;
}

int main(){
    size_t n,m;
    std::cin >> n;
    std::cin.ignore();
    std::deque<std::string> dq;

    for (size_t i = 0; i < n; i++)
    {
        std::string s;
        std::getline(std::cin, s);
        auto ret = split(s);
        std::string name, order;
        name = ret[0];
        order = ret[1];
        if (order == "top"){
            dq.push_front(name);
        } else if (order == "bottom"){
            dq.push_back(name);
        }
    }
    std::cin >> m;
    std::vector<int> nums;
    for (size_t i = 0; i < m; i++)
    {
        int num;
        std::cin >> num;
        nums.push_back(num-1);
    }

    for(auto idx: nums){
        std::cout<< dq[idx] << '\n';
    }
}