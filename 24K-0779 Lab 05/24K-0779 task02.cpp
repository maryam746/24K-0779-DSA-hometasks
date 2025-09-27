#include <iostream>
using namespace std;

const int n=5;

bool safe(int maze[n][n],int x,int y,int sol[n][n]){
    return (x>=0 && x<n && y>=0 && y<n && maze[x][y]==1 && sol[x][y]==0);
}

bool go(int maze[n][n],int x,int y,int sol[n][n]){
    if(x==n-1 && y==n-1 && maze[x][y]==1){
        sol[x][y]=1;
        return true;
    }
    if(safe(maze,x,y,sol)){
        sol[x][y]=1;
        if(go(maze,x+1,y,sol)) return true;
        if(go(maze,x,y+1,sol)) return true;
        if(go(maze,x-1,y,sol)) return true;
        if(go(maze,x,y-1,sol)) return true;
        sol[x][y]=0;
        return false;
    }
    return false;
}

int main(){
    int maze[n][n]={
        {1,0,0,0,0},
        {1,1,1,1,0},
        {0,0,0,1,0},
        {1,1,0,1,1},
        {0,1,1,1,1}
    };
    int sol[n][n]={0};
    if(go(maze,0,0,sol)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<sol[i][j]<<" ";
            cout<<endl;
        }
    }
}
