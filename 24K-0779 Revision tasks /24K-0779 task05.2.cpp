#include <iostream>
#include<vector>
using namespace std;

void findallpaths(int grid[5][5], int row, int col, int targetr, int targetc, vector<pair<int,int> >& path, bool visited[5][5]){

    if(row < 0 || row >= 5 || col < 0 || col >= 5) return;
    if(grid[row][col] == 0 || visited[row][col]) return;

    visited[row][col] = true;
    path.push_back(make_pair(row,col));
    
    if(row == targetr && col == targetc) {
        for(int i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << "," << path[i].second << ")";
            if(i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        findallpaths(grid, row, col + 1, targetr, targetc, path, visited);
        findallpaths(grid, row + 1, col, targetr, targetc, path, visited);
        findallpaths(grid, row, col - 1, targetr, targetc, path, visited);
        findallpaths(grid, row - 1, col, targetr, targetc, path, visited);
    }

    path.pop_back();
    visited[row][col] = false;
}    

int main()
{
    int arr[5][5] = {
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };
    
    vector<pair<int,int> > path;
    bool visited[5][5] = {false};
    
    cout << "cat paths from (4,4) to (2,2):" << endl;
    findallpaths(arr, 4, 4, 2, 2, path, visited);
    
    return 0;
}
