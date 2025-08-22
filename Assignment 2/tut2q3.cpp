#include<iostream>
using namespace std;
int main(){
    int n =9;
    int diff=0;
    int a[]={0,1,2,4,5,6,7,8,};
    for(int i=0;i<n;i++){
if(a[i]-i!=diff){
    while(diff<a[i]-i){
        cout<<i+diff;
        diff++;
    }
}}
}