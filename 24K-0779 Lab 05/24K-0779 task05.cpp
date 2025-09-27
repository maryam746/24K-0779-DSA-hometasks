#include <iostream>
using namespace std;

int sumdig(int n){
    if(n==0) return 0;
    return n%10+sumdig(n/10);
}

int nest(int n){
    if(n<10) return n;
    return nest(sumdig(n));
}

int main(){
    int x;
    cin>>x;
    cout<<nest(x)<<endl;
}
