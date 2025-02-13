#include <iostream>
#include <vector>

int main(){
    size_t n, k;
    std::cin >> n >> k;
    std::vector<int> vec1;
    std::vector<int> vec2;
    for (size_t i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        vec1.push_back(temp);
    }

    for (size_t i = 0; i < k; i++)
    {
        int temp;
        std::cin >> temp;
        vec2.push_back(temp);
    }

    for(auto& item: vec2){
        auto temp = std::lower_bound(vec1.begin(), vec1.end(), item);
        //std::cout << "lower bond for" << item << " is " << *temp << '\n';
        auto prev = temp;
        if(temp != vec1.begin()){
            //std::cout << "temp is not last element" << '\n';
            prev--;
            if(std::abs(*temp - item) < std::abs(*(prev) - item)){
                //std::cout << "temp is nearest element to item" << '\n';
                std::cout << *temp << '\n';
            } else{
                //std::cout << "temp is not nearest element to item, nearest is " << *prev << '\n';
                std::cout << *prev << '\n';
            }
        } else if(temp == vec1.end()){
            //std::cout << "temp is nearest element to item" << '\n';
            auto last = vec1.end();
            last--;
            std::cout << *last << '\n';
        } else {
            std::cout << *temp << '\n';
        }
    }
    
}