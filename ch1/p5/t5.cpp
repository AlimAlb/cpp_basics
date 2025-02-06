#include <iostream>
#include <vector>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix){
    
    std::vector<std::vector<int>> t;
    for (size_t i = 0; i < matrix[0].size(); i++)
    {
        std::vector<int> row;
        for (size_t j = 0; j < matrix.size(); j++)
        {
            row.push_back(matrix[j][i]);
        }
        t.push_back(row);
    }

    return t;
}


int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    std::vector<std::vector<int>> matrix;
    for (size_t i = 0; i < n; i++)
    {
        std::vector<int> row;
        for (size_t j = 0; j < m; j++)
        {
            int num;
            std::cin >> num;
            row.push_back(num);
        }
        matrix.push_back(row);
    }
    auto res = Transpose(matrix);    

    for (size_t i = 0; i != res.size(); i++)
    {
        for (size_t j = 0; j < res[0].size(); j++)
        {
            std::cout << res[i][j] << ' ';
        }
        std::cout << '\n';
        
    }
    
}