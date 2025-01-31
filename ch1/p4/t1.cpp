#include <iostream> 

int main() {
    std::string s;
    std::cin >> s;
    
    bool check_ascii = true;
    bool class_1 = false;
    bool class_2 = false;
    bool class_3 = false;
    bool class_4 = false;

    for (size_t i = 0; i != s.size(); i++)
    {
        if (s[i] < 33 || s[i] > 126){
            check_ascii = false;
        }
        
        if (s[i] >= 'A' && s[i] <= 'Z'){
            class_1 = true;
        }

        if (s[i] >= '0' && s[i] <= '9'){
            class_2 = true;
        }
        
        if (s[i] >= 'a' && s[i] <= 'z'){
            class_3 = true;
        }

        if (!((s[i] >= 'a' && s[i] <= 'z') ||
        (s[i] >= '0' && s[i] <= '9') || 
         (s[i] >= 'A' && s[i] <= 'Z'))){
            class_4 = true;
         }

    }

    if (check_ascii && s.size() >= 8 && s.size() <= 14
     && (class_1 + class_2 + class_3 + class_4) >= 3){
        std::cout << "YES\n";
     } else {
        std::cout << "NO\n";
     }
    


}