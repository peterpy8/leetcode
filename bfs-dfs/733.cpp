#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print(vector<int> values)
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

void print(vector<vector<int>> values)
{
    for(auto val : values)
    {
        print(val);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image,
                              int sr, int sc, int newColor)

{
    int m = image.size();
    int n = image[0].size();
    vector<vector<int>> visited (m, vector<int>(n, 0));
    vector<vector<int>> result = image;

    queue<pair<int, int>> floodedNodes;
    floodedNodes.push(make_pair(sr,sc));

    while (!floodedNodes.empty())
    {
        pair<int, int> curr = floodedNodes.front();
        floodedNodes.pop();

        visited[curr.first][curr.second] = 1;
        result[curr.first][curr.second] = newColor;

        if (curr.first >= 1)
        {
            int newRow = curr.first - 1;
            int newCol = curr.second;
            if (image[curr.first][curr.second] == image[newRow][newCol] && visited[newRow][newCol] == 0)
            {
                floodedNodes.push(make_pair(newRow,newCol));
            }
        }
        
        if (curr.first < m - 1)
        {
            int newRow = curr.first + 1;
            int newCol = curr.second;
            if (image[curr.first][curr.second] == image[newRow][newCol] && visited[newRow][newCol] == 0)
            {
                floodedNodes.push(make_pair(newRow,newCol));
            }
        }

        if (curr.second >= 1)
        {
            int newRow = curr.first;
            int newCol = curr.second - 1;
            if (image[curr.first][curr.second] == image[newRow][newCol] && visited[newRow][newCol] == 0)
            {
                floodedNodes.push(make_pair(newRow,newCol));
            }
        }
        
        if (curr.second < n - 1)
        {
            int newRow = curr.first;
            int newCol = curr.second + 1;
            if (image[curr.first][curr.second] == image[newRow][newCol] && visited[newRow][newCol] == 0)
            {
                floodedNodes.push(make_pair(newRow,newCol));
            }
        }
    }

    return result;
}

int main()
{
    /*
    vector<vector<int>> input = {{1,1,1}, {1,1,0}, {1,0,1}};
    print(input);

    cout << "output:" << endl;

    print(floodFill(input, 1, 1, 2));
    */
    vector<vector<int>> input = {{0,0,0},
                                 {0,0,0},
                                 {0,0,0}};
    print(input);

    cout << "output:" << endl;

    print(floodFill(input, 0, 0, 2));

}
