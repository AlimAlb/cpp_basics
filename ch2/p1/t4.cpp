#include <iostream>
#include <list>


int main(){
    std::list<std::string> text;
    std::string s = "temp";
    while(std::getline(std::cin, s)){
        if(s.empty()){
            text.push_back("_");
            break;
        }
        else {
            text.push_back(s);
        }
    }

    // std::cout << "begining:\n";
    // for(auto str: text){
    //      std::cout << str << '\n';
    //  }
    // std::cout << '\n';

    std::string operation = "temp";
    auto iter = text.begin();
    std::string buffer = "";
    while(std::getline(std::cin, operation) && operation != "end"){
        if(operation == "Down"){
            if(std::next(iter) != text.end()){
                iter++;
            }
        }
        else if(operation == "Up"){
            if(iter != text.begin()){
                iter--;
            }
        }

        else if(operation == "Ctrl+X"){
            if((*iter) != "_"){
            buffer = *iter;
            iter = text.erase(iter);
            }
        }
        else if (operation == "Ctrl+V"){
            if(!buffer.empty()){
                iter = text.insert(iter, buffer);
                iter++;
            }           
        }
        // std::cout << "operation: " << operation << '\n';
        // std::cout << "cursor: " << *iter << '\n';
        // for(auto obj: text){
        // std::cout << obj << '\n';
        // }
    }

    //std::cout << "end:\n";
    for(auto obj: text){
        if(obj != "_"){
            std::cout << obj << '\n';
        }
    }
}





