#include <iostream>
#include <string>


bool NextToken(std::string_view& sv, char delim, std::string_view& token){
    if(sv.size() == 0){
        return false;
    } 
    size_t idx = 0;
    while(sv[idx]!= delim && idx != sv.size()){
        idx++;
    }
    token = sv.substr(0, idx);
    if(idx < sv.size()){
        sv.remove_prefix(idx+1);
    } else {
        sv = "";
    }

    return true;
}


int main() {
    std::string_view sv = "Hello world and good bye";

    const char delimiter = ' ';
    std::string_view token;
    int idx = 3;
    // Делим строку на токены по разделителю и перебираем эти токены:
    while (NextToken(sv, delimiter, token)) {
        // обрабатываем очередной token
        // например, печатаем его на экране:
        std::cout << "token:" << token << "\n";
        std::cout << "sv:" << sv << "\n";
        std::cout <<'\n';
    }
}