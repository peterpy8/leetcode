#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
void print(vector<T>& values)
{

    cout << "[";
    for (int i = 0; i < values.size(); ++i)
    {

        if (i == 0)
        {
            cout << values[i];
        }
        else
        {
            cout << ", " << values[i];
        }
        
    }

    cout << "]" << endl;
}

template <typename T>
void print(vector<vector<T>>& values)
{
    for(auto val : values)
    {
        print(val);
    }
}

int numIslands(vector<vector<char>>& grid) {
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int islandCount = 0;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == '0' || visited[i][j])
                continue;

            queue<pair<int, int>> neighbors;
            neighbors.push(pair<int, int>(i, j));

            while (!neighbors.empty())
            {
                auto currNode = neighbors.front();
                //std::cout << "[" << i << "][" << j << "]: current node at: " << currNode.first << "," << currNode.second << endl;
                neighbors.pop();
                grid[currNode.first][currNode.second] = '0' + islandCount + 2;

                for (vector<int> direction : directions)
                {
                    pair<int, int> newNode = make_pair(currNode.first + direction[0], currNode.second + direction[1]);
                    if (newNode.first >= m || newNode.first < 0 ||
                        newNode.second >= n || newNode.second < 0 || visited[newNode.first][newNode.second] || grid[newNode.first][newNode.second] == '0')
                    {
                        continue;
                    }

                    // put here to aviod infinitive loop
                    visited[newNode.first][newNode.second] = true;
                    neighbors.push(newNode);
                }

                //print(grid);
                
            }

            islandCount++;
            print(visited);
            std::cout << islandCount << endl;
        }
    }

    return islandCount;
}

int main()
{
    vector<vector<char>> input = {
        {'1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '0',
         '1',
         '1'},
        {'0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0'},
        {'1',
         '0',
         '1',
         '1',
         '1',
         '0',
         '0',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'},
        {'1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'},
        {'1',
         '0',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'},
        {'1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1'},
        {'0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1'},
        {'1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1'},
        {'1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'},
        {'1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'},
        {'0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'},
        {'1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'},
        {'1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'},
        {'1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'},
        {'1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1'},
        {'1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0'},
        {'1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '0',
         '1',
         '1',
         '1',
         '1',
         '0',
         '0'},
        {'1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'},
        {'1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'},
        {'1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1',
         '1'}};

    print(input);

    std::cout << "output:" << endl;

    std::cout << numIslands(input) << endl;
}
