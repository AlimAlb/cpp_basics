#include <iostream>
#include <vector>
#include <sstream>
#include <utility>

using namespace std;

int main(){
    // std::cin.ignore();
    // string s;

    // std::getline(std::cin, s);
    int rows, cols, mines;
    scanf("%d%d%d", &rows, &cols, &mines);
    vector<pair<int, int>> coor;


    for (int i = 0; i < mines; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        coor.push_back(pair<int, int> (x-1, y-1));
    }


    vector<vector<char>> map(rows, vector<char>(cols));

    for (size_t i = 0; i < coor.size(); i++)
    {
        map[coor[i].first][coor[i].second] = '*';
    }
    

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (map[i][j] != '*'){
                map[i][j] = '0' + ((i < rows-1) && map[i+1][j] == '*') +
                ((i > 0) && map[i-1][j] == '*') + 
                ((j < cols-1) && map[i][j+1] == '*') +
                ((j > 0) && map[i][j-1] == '*') + 
                ((i > 0)  && (j>0) && map[i-1][j-1] == '*') + 
                ((i < rows-1)  && (j > 0) && map[i+1][j-1] == '*') + 
                ((i < rows-1)  && (j < cols-1) && map[i+1][j+1] == '*') + 
                ((i > 0 )  && (j < cols-1) && map[i-1][j+1] == '*');
            }
            
        }
        
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
        
    }
    
    
    

}