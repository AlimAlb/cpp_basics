#include <iostream>
#include <string>
#include <stack>
#include <map>

int main(){
    std::string s;
    std::getline(std::cin, s);
    std::stack<char> stac;
    std::map<char, char> mp = {{'(',')'}, {'{','}'},{'[',']'}};
    bool flag = true;
    for(char sym: s){
        if(sym == '(' || sym == '{' || sym == '['){
            stac.push(sym);
        } else {
            if(!stac.empty()){
                if(mp[stac.top()] == sym){
                    stac.pop();
                } else {
                    flag = false;
                    break;
                }
            } else {
                flag = false;
                break;
            }
        }
    }
    if(!stac.empty()){
        flag = false;
    }
    if (flag){
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}