#include<iostream>
using namespace std;
void buubleSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){
    int n=7;
    int a[n]={64,34,25,12,22,11,90};
    for(int i=0;i<7;i++){
        cout<<" "<<a[i];
    }
    buubleSort(a,n);
     for(int i=0;i<7;i++){
        cout<<" "<<a[i];
    }
}