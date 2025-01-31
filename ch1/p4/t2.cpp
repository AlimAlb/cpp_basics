#include <iostream>

int main(){
   std::string del = "aehiouwy"; // все символы отсюда удалить
   std::vector<std::string> rep = {"bfpv", "cgjkqsxz", "dt", "l", "mn", "r"}; // все символы отсюда заменить на idx + 1
   
   
   int idx = s.find('s');
   s.replace(idx, 1, "");
   idx = s.find('s');
   std::cout << idx << '\n';
   std::cout << s << '\n'; 
}