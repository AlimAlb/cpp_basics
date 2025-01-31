#include <iostream>

int main(){
    long long n;
    std::cin >> n;
    int s = 0;
    while (n > 0){
        s += n % 10;
        n = n / 10;
    }

    std::cout << s << '\n';
}