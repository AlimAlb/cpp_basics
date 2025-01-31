#include <iostream>

int main(){
    int n;
    std::cin >> n;
    float s = 0;
    for (int i = 1; i < n+1; i++)
    {
        int one = 0;
        if (i % 2 == 0){
            one = -1;
        } else {
            one = 1;
        }
        s += (one * 1.0) / i;
    }
    std::cout << s << '\n';
}