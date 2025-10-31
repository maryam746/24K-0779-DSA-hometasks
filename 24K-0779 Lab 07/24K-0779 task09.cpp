#include <iostream>
using namespace std;

int getmax(int a[],int n){
 int m=a[0];
 for(int i=1;i<n;i++)if(a[i]>m)m=a[i];
 return m;
}

void countsort(int a[],int n,int exp){
 int out[n],cnt[10]={0};
 for(int i=0;i<n;i++)cnt[(a[i]/exp)%10]++;
 for(int i=1;i<10;i++)cnt[i]+=cnt[i-1];
 for(int i=n-1;i>=0;i--){
  int idx=(a[i]/exp)%10;
  out[cnt[idx]-1]=a[i];
  cnt[idx]--;
 }
 for(int i=0;i<n;i++)a[i]=out[i];
}

void radixsort(int a[],int n){
 int m=getmax(a,n);
 for(int exp=1;m/exp>0;exp*=10)countsort(a,n,exp);
}

int main(){
 int n; 
 cout<<"enter number of transactions:"<<endl; 
 cin>>n;
 int a[n];
 cout<<"enter transaction amounts:"<<endl;
 for(int i=0;i<n;i++)cin>>a[i];
 radixsort(a,n);
 cout<<"sorted transactions:"<<endl;
 for(int i=0;i<n;i++)cout<<a[i]<<endl;
}
