#include<iostream>
using namespace std;
int main(){
    int n=8;
    int i;
    int a[n]={1,2,2,3,4,4,5,5};
    for( i=0;i<n;i++){
for(int j =i+1;j<n;j++){
    if(a[i]!=a[j]){
        a[i+1]=a[j];
        n--;
        i++;
    }
}
    }
    cout<<i;
    
}