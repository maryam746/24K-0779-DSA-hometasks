#include <iostream>
using namespace std;

int n,cnt=0;

bool safe(int board[20][20],int r,int c){
    for(int i=0;i<c;i++) if(board[r][i]) return false;
    for(int i=r,j=c;i>=0&&j>=0;i--,j--) if(board[i][j]) return false;
    for(int i=r,j=c;i<n&&j>=0;i++,j--) if(board[i][j]) return false;
    return true;
}

bool place(int board[20][20],int c){
    if(c==n){
        cnt++;
        if(cnt==1){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++) cout<<(board[i][j]?'Q':'.')<<" ";
                cout<<endl;
            }
        }
        return false;
    }
    for(int i=0;i<n;i++){
        if(safe(board,i,c)){
            board[i][c]=1;
            place(board,c+1);
            board[i][c]=0;
        }
    }
    return false;
}

int main(){
    cin>>n;
    int board[20][20]={0};
    place(board,0);
    cout<<"total "<<cnt<<endl;
}
