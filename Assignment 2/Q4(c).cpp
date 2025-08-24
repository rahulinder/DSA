#include<iostream>
using namespace std;
void del(char arr[],int size,int pos){
    int j;
    for( j=pos;j<size-1;j++){
        arr[j]=arr[j+1];
    } j--;
        size--;
    }

int main(){
    char a[]= "well";
   int len=printf("well");
    //cout<<len;
    int vcount=0;
    int i;
    for( i=0;a[i]!='\0';i++){

        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
            vcount ++;
            int j;
    for( j=i;j<len;j++){
        a[j]=a[j+1];
    } 
        len--;
    }

        }
       a[len+1]='\0';
        cout<<a;
}
