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
 int a[50]={85,92,76,88,69,95,74,91,67,83,90,100,56,78,84,63,99,79,81,68,72,87,80,94,60,55,82,73,89,96,58,64,97,71,70,93,75,62,61,66,98,59,77,65,86,57,54,52,53,50};
 radixsort(a,50);
 cout<<"sorted scores with ranks:"<<endl;
 for(int i=0;i<50;i++)cout<<"rank "<<i+1<<": "<<a[i]<<endl;
 cout<<endl;
}
