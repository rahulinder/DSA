#include<iostream>
using namespace std;
int main(){
    char a[]="welcome";
int i;
for(int i=0;a[i]!=0;i++){
    if(a[i]>=97&&a[i]<=122){
        a[i]=a[i]-32;
    }
}
cout<<a;
}