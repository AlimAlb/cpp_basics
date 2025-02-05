#include <iostream>

using namespace std;


int main(){
    string s;
    getline(cin, s);
    string clean;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] != ' '){
            clean.push_back(s[i]);
        }
    }

    int left = 0;   
    int right = clean.size()-1;
    bool flag = true;
    while (left <= right){
        if (clean[left++] != clean[right--]){
            flag = false;
            break;
        }
    }

    if (flag){
        cout << "YES" << '\n';
    } else{
        cout << "NO" << '\n';
    }
}