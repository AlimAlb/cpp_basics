#include <iostream>
#include <cstdint>

int main(){
    int a, b, c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    if ((a + b) < c || (a + c) < b || (c + b) < a){
        std::cout << "UNDEFINED" << '\n'; 
    } else if ((a*a + b*b) == c*c || (a*a + c*c) == b*b || (c*c + b*b) == a*a){
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';  
    }
}