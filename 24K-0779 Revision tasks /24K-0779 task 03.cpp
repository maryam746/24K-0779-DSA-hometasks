// For multiple paths, the algorithm follows movement priority: Right -> Down -> Left -> Up
// It takes the first successful path found using depth-first search with this order
#include <iostream>
#include<vector>
using namespace std;

bool findpath(int grid[4][4], int row, int col, vector<pair<int,int> >& path, bool visited[4][4]){

    if(row < 0 || row >= 4 || col < 0 || col >= 4) return false;
    if(grid[row][col] == 0 || visited[row][col]) return false;

    visited[row][col] = true;
    path.push_back(make_pair(row,col));
    
    if(row == 3 && col == 3) return true;

    if(findpath(grid, row, col + 1, path, visited)) return true;
    if(findpath(grid, row + 1, col, path, visited)) return true;
    if(findpath(grid, row, col - 1, path, visited)) return true;
    if(findpath(grid, row - 1, col, path, visited)) return true;

    path.pop_back();
    return false;
}    

int main()
{
    int arr[4][4] = {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };
    
    vector<pair<int,int> > path;
    bool visited[4][4] = {false};
    
    if(findpath(arr, 0, 0, path, visited)) {
        cout << "robot path: ";
        for(int i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << "," << path[i].second << ")";
            if(i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "no path found" << endl;
    }
    
    return 0;
}
