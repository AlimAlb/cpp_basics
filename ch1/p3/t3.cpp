#include <iostream>

int main(){
    int n;
    std::cin >> n;
    if (n % 400 == 0) {
        std::cout << "YES\n";
    } else if (n % 100 == 0){
        std::cout << "NO\n";
    } else if (n % 4 == 0) {
        std::cout << "YES\n";
    } else {
        std:: cout << "NO\n";
    }
}