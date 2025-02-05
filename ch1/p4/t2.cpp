#include <iostream>
#include <string>
#include <vector>

int main(){
   std::string del = "aehiouwy"; // все символы отсюда удалить
   std::vector<std::string> rep  = {"bfpv", "cgjkqsxz", "dt", "l", "mn", "r"}; // все символы отсюда заменить на idx + 1
   
   std::string s;
   std::cin >> s;

   // delete all del chars
   size_t idx = 1;
   while (idx != s.size()){
      bool flag = false;
      for (size_t i = 0; i != del.size(); i++)
      {
         if (s[idx] == del[i]){
            flag = true;
         }
      }
      if (flag) {
         s.erase(idx, 1);
         //s.replace(idx, 1, "");
      }
      else{
         idx += 1;
      }
   }
   std::cout << s << '\n';
   std::cout << s.size() << '\n';

   // replace all rep chars
   for (size_t i = 1; i != s.size(); i++)
   {
      bool f1 = false;
      for (size_t j = 0; j < rep[0].size(); j++)
      {
         if (s[i] == rep[0][j]){
            f1 = true;
            break;
         }
      }
      
      bool f2 = false;

      for (size_t j = 0; j < rep[1].size(); j++)
      {
         if (s[i] == rep[1][j]){
            f2 = true;
            break;
         }
      }

      if (f1){
         s.replace(i, 1, "1");
      } else if (f2){
         s.replace(i, 1, "2");
      } else if (s[i] == 'd' || s[i] == 't'){
         s.replace(i, 1, "3");
      } else if (s[i] == 'l'){
         s.replace(i, 1, "4");
      } else if (s[i] == 'm' || s[i] == 'n'){
         s.replace(i, 1, "5");
      } else if (s[i] == 'r'){
         s.replace(i, 1, "6");
   }
   }
   std::cout << s << '\n';
   std::cout << s.size() << '\n';

   // replace repeating chars with one of their kind
   size_t start = 1;
   size_t curr = 2;
   bool seq_start = false;
   bool seq_end = false;
   while (curr <= s.size()){
      if (s[curr] == s[start]){
         curr++;
         seq_start = true;
      } 
      if (curr == s.size() || s[curr] != s[start]){
         if(seq_start){
            s.replace(start, curr-start, 1, s[start]); 
            seq_start = false;
            //std::cout << s << '\n';
            curr = start + 1;
         } else {
            curr++;
            start++;
         }
         
      }
   }
   std::cout << s << '\n';
   std::cout << s.size() << '\n';
   // trim to 4 chars or complete to 4 chars with zeros
   if (s.size() > 4){
      s.erase(4, s.size() - 4);
   } else if (s.size() < 4){
      while(s.size() != 4){
         s.push_back('0');
      }
   }
   std::cout << s << '\n';
}