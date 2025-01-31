#include <iostream>
#include <cstdint>

int main(){
    int32_t n, k;
    std::cin >> n >> k;
    bool flag = false;
    for (int i = 0; i < (n + k - 1)/7 + 1; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (7*i + j < n-1){
                std::cout << "  ";
            } else if (7*i + j - n + 2 > k){
                break;
            } else {
                if (7*i + j - n + 2 < 10){
                    std::cout << ' ';
                }
                std::cout << 7*i + j - n + 2;
            }
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}