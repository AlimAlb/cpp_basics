#include <iostream>
#include <list>


int main(){
    std::list<std::string> text;
    std::string s = "temp";
    while(std::getline(std::cin, s)){
        if(s.empty()){
            //text.push_back("_");
            break;
        }
        else {
            text.push_back(s);
        }
    }


    std::string operation = "temp";
    auto iter = text.begin();
    auto start = text.begin();
    std::list<std::string> shift_buffer;
    bool shift = false;
    std::string buffer = "";

    
    while(std::getline(std::cin, operation) && operation != "end"){
        if(operation == "Down"){
            if(std::next(iter) != text.end()){
                iter++;
            } 
        } else if(operation == "Up"){
            if (shift){
                if(start != text.begin()){
                    start--;
                }
            }
             else if (iter != text.begin()){
                iter--;
            }
        } else if(operation == "Shift"){
            shift = true;
            start = iter;
        } 
        
        
        else if(operation == "Ctrl+X"){
            if(shift){
                shift_buffer.clear();
                shift_buffer.splice(shift_buffer.begin(), text, start, iter);
                start = iter;
                shift = false;
            } else if((*iter) != "_"){
                buffer = *iter;
                iter = text.erase(iter);
            }
            
        } else if (operation == "Ctrl+V"){
            if(!shift_buffer.empty() && start != iter){
                iter = text.erase(start, iter);
                iter = text.insert(iter, shift_buffer.begin(), shift_buffer.end());
                start = iter;
                shift = false;
            }
            else if(!buffer.empty()){
                iter = text.insert(iter, buffer);
                iter++;
            }           
        }
        // ниже вывод для отладки
        // std::cout << "operation: " << operation << '\n';
        // std::cout << "cursor: " << *iter << '\n';
        // std::cout << "start: " << *start << '\n';
        // std::cout << "buff: " << buffer << '\n';
        // std::cout << "shift_buff: ";
        // for(auto item: shift_buffer){
        //     std::cout << item << '|';
        // }
        // std::cout << '\n';
        // for(auto item: text){
        //     std::cout << item << '|';
        // }
        // std::cout << '\n' << '\n';
    }


    for(auto obj: text){
        if(obj != "_"){
            std::cout << obj << '\n';
        }
    }
}
