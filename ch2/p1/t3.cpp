// Осталось доделать удаление (удалять надо сразу диапазон - для этого есть специальный erase)
#include <iostream>
#include <list>
#include <tuple>
#include <sstream>
#include <deque>

std::tuple<char, int, int> read_operation(std::string& input, std::tuple<char, int, int>& tup){
    char op;
    int  num, side;
    std::string s_side, s_num;
    op = input[0];
    size_t idx = 1;
    while (input[idx] != ' '){
        //std::cout << input[idx] << '\n';
        s_side.push_back(input[idx]);
        idx++;
    }
    idx++;
    while(idx < input.size()){
        s_num.push_back(input[idx]);
        idx++;
    }
    //std::cout << s_side << '\n';
    //std::cout << s_num << '\n';
    num = stoi(s_num);
    if (s_side == "left"){
        side = 0;
    } else if (s_side == "right"){
        side = 1;
    }
    tup = std::make_tuple(op, side, num);
    return tup;
}

std::tuple<char, int, int> read_op(std::string& input, std::tuple<char, int, int>& tup){
    char op;
    std::string s_side;
    int num, side;
    std::istringstream ss(input);
    ss >> op >> s_side >> num;
    if (s_side == "left"){
        side = 0;
    } else if (s_side == "right"){
        side = 1;
    }
    tup = std::make_tuple(op, side, num);
    return tup;
}

void MakeTrian(){
    std::string input;
    std::deque<int> lst;
    while (std::getline(std::cin, input) && input != "end"){
        std::tuple<char, int, int> tup;
        auto [op, side, num] = read_op(input, tup);
        if(op == '+'){
            if(side){
                lst.push_back(num);
            } else {
                lst.push_front(num);
            }
        } 
        else if (op == '-'){
            if(side){
                auto it1 = lst.rbegin();
                auto it2 = lst.rbegin();
                if (static_cast<size_t>(num) < lst.size()){
                    std::advance(it2, num);    
                } else {
                    lst.clear();
                }
                lst.erase(it2.base(), it1.base());
            } else {
                auto it1 = lst.begin();
                auto it2 = lst.begin();
                if (static_cast<size_t>(num) < lst.size()){
                    std::advance(it2, num);    
                } else {
                    lst.clear();
                }
                lst.erase(it1, it2);

            }
        }
        
    }

    for(auto item: lst){
            std::cout << item << ' ';
        }
        std::cout << '\n';

}


int main(){
    MakeTrian();
}