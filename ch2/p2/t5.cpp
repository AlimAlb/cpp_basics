#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

void find_ngrams(int len, std::string& word, std::map<std::string, int>& ngrams){
    size_t start = 0;
    if(static_cast<size_t>(len) > word.size()){
        return;
    }
    while(start != word.size()-len+1){
        ++ngrams[word.substr(start, len)];
        ++start;
    }

}

int main(){
    size_t words;
    int  ngram_len;
    std::string word;
    std::map<std::string, int> map;
    scanf("%zd %d", &words, &ngram_len);
    for (size_t i = 0; i < words; i++)
    {
        std::cin >> word;
        find_ngrams(ngram_len, word, map);
    }
    std::vector<std::pair<std::string, int>> vec(
        map.begin(),
        map.end()
    );
    std::sort(
        vec.begin(),
        vec.end(),
        [](const auto& p1, const auto& p2){
            if(p1.second != p2.second){
                return p1.second > p2.second;
            } else{
                return p1.first < p2.first;
            }
            
        }
    );
    for(auto& [ngram, count]: vec){
        std::cout << ngram << " - " << count << '\n';
    }
}