#include <iostream>
#include <cstdint>
#include <cmath>

int main(){
    int8_t x0, y0, x, y;
    std::cin >> x0;
    std::cin >> y0;
    std::cin >> x;
    std::cin >> y;

    if (x0 == x || y0 == y || std::abs(x0 - x) == std::abs(y0-y)){
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}