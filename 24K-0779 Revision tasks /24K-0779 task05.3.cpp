#include <iostream>
#include<vector>
#include<set>
using namespace std;

void findallpaths(int grid[5][5], int row, int col, int targetr, int targetc, vector<pair<int,int> >& path, vector<vector<pair<int,int> > >& allpaths, bool visited[5][5]){

    if(row < 0 || row >= 5 || col < 0 || col >= 5) return;
    if(grid[row][col] == 0 || visited[row][col]) return;

    visited[row][col] = true;
    path.push_back(make_pair(row,col));
    
    if(row == targetr && col == targetc) {
        allpaths.push_back(path);
    } else {
        findallpaths(grid, row, col + 1, targetr, targetc, path, allpaths, visited);
        findallpaths(grid, row + 1, col, targetr, targetc, path, allpaths, visited);
        findallpaths(grid, row, col - 1, targetr, targetc, path, allpaths, visited);
        findallpaths(grid, row - 1, col, targetr, targetc, path, allpaths, visited);
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
    
    vector<vector<pair<int,int> > > rabbitpaths;
    vector<vector<pair<int,int> > > catpaths;
    vector<pair<int,int> > path;
    bool visited[5][5] = {false};
    
    cout << "finding intersections..." << endl;
    
    findallpaths(arr, 0, 0, 2, 2, path, rabbitpaths, visited);
    findallpaths(arr, 4, 4, 2, 2, path, catpaths, visited);
    
    set<pair<int,int> > intersections;
    
    for(int i = 0; i < rabbitpaths.size(); i++) {
        for(int j = 0; j < catpaths.size(); j++) {
            for(int k = 0; k < rabbitpaths[i].size(); k++) {
                for(int l = 0; l < catpaths[j].size(); l++) {
                    if(rabbitpaths[i][k] == catpaths[j][l] && !(rabbitpaths[i][k].first==2 && rabbitpaths[i][k].second==2)) {
                        intersections.insert(rabbitpaths[i][k]);
                    }
                }
            }
        }
    }
    
    if(!intersections.empty()) {
        cout << "intersection points: ";
        for(set<pair<int,int> >::iterator it = intersections.begin(); it != intersections.end(); it++) {
            cout << "(" << it->first << "," << it->second << ") ";
        }
        cout << endl;
    } else {
        cout << "no intersections found" << endl;
    }
    
    return 0;
}
