#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

// bool compare(std::string dir1, std::string dir2){
//     if (dir1.size() != dir2.size()){
//         return false;
//     }
//     size_t n = dir1.size();
//     for (size_t i = 0; i < n; i++)
//     {
//         if(dir1[i] != dir2[i]){
//             return false;
//         }
//     }
//     return true;
// }

void extract_dir_rec(std::string& path, std::vector<std::string>& dirs){
    // сначала обрезать все до первого слеша с конца
    if(path.empty() || path.find_last_of('/') == 0){ // пустой путь или файл - базовый случай
        dirs.push_back("/");
        return;
    } else {
        size_t pos = path.find_last_of('/');
        std::string parent_path = path.substr(0, pos);

        extract_dir_rec(parent_path, dirs);
        dirs.push_back(parent_path);
    }
    
}

// тут нужно возвращать список всех директорий, попробовать рекурсивный алгоритм
void extract_dir(std::string& path, std::string& dir){
    int max_idx = 0;
    for (size_t i = 0; i != path.size(); i++)
    {
        if(path[i] == '/'){
            max_idx = i;
        }
    }
    dir = path.substr(0, max_idx+1);
}


int main(){
    std::string s;
    std::vector<std::string> vec;
    std::unordered_set<std::string> dirs;

    while(std::cin >> s){
        extract_dir_rec(s, vec);
        for(auto& item: vec){
            dirs.insert(item);
        }        
        vec.clear();
    }
    std::vector<std::string> vec_dirs (dirs.begin(), dirs.end());
    std::sort(vec_dirs.begin(), vec_dirs.end());
    for(auto& dir: vec_dirs){
        std::cout << dir;
        if(dir != "/"){
            std::cout << '/';
        }
        std::cout << '\n';
        
    }
}