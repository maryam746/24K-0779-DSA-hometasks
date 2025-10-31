#include <iostream>
using namespace std;

class order{
public:
 int id; string name; int price;
};

void swap(order &a,order &b){
 order t=a; a=b; b=t;
}

int part(order a[],int l,int h){
 int p=a[h].price,i=l-1;
 for(int j=l;j<h;j++){
  if(a[j].price<p){i++;swap(a[i],a[j]);}
 }
 swap(a[i+1],a[h]);
 return i+1;
}

void qsort(order a[],int l,int h){
 if(l<h){
  int pi=part(a,l,h);
  qsort(a,l,pi-1);
  qsort(a,pi+1,h);
 }
}

int main(){
 order o[5];
 for(int i=0;i<5;i++){
  cout<<"enter orderid name totalprice: ";
  cin>>o[i].id>>o[i].name>>o[i].price;
 }
 qsort(o,0,4);
 cout<<"sorted orders:"<<endl;
 for(int i=0;i<5;i++)cout<<o[i].id<<" "<<o[i].name<<" "<<o[i].price<<endl;
}
