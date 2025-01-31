#include <iostream>

int main(){
    int year, month;
    std::cin >> month >> year;
    bool is_vis = false;
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 ==0)) {
        is_vis = true;
    }
    if (month == 2){
        if (is_vis) {
            std::cout << 29 << '\n';
        } else {
            std::cout << 28 << '\n';
        }
    } else if (month == 1 || month ==  3 || month == 5 || month == 7 
    || month == 8 || month == 10 || month == 12) {
        std::cout << 31 << '\n';
    } else {
        std::cout << 30 << '\n';
    }
}