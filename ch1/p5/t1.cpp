#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<size_t, size_t> MatrixArgMax(const std::vector<vector<int>>& matrix){
    int max_i = 0;
    int max_j = 0;
    int max = matrix[0][0];

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] > max){
                max_i = i;
                max_j = j;
                max = matrix[i][j];
            }
        }
        
    }

    return pair<int, int>(max_i, max_j);
    
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> matrix;
    for (size_t i = 0; i != n; i++)
    {
        vector<int> row;
        for (size_t j = 0; j != m; j++)
        {
            int item;
            cin >> item;
            row.push_back(item);
        }
        matrix.push_back(row);
        
    }

    pair<int, int> res = MatrixArgMax(matrix);
    
    cout << res.first << " " << res.second << '\n';
}