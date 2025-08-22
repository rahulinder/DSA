#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int x){
    int low=0;
    int high=size-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==x){
            return x;
        }
        else if (arr[mid]>x){
            high=mid-1;}
            else
            low=mid-1;

        }
    return -1;
    }
int main(){
    int a[7]={1,3,5,7,11,13,19};
    int x=13;
   int result= binarysearch(a,7,13);
   if (result==-1){
    cout<<x<<" is not present in this array";

   }
   else 
   cout<<"the index of value is "<<x;
    

}