#include<iostream>
using namespace std;
class complex;
class calculator{
    public:
    int add(int a,int b){
        return (a+b);
    }
    int sumRealcomplex(complex o1,complex o2);
    };

class complex {
    int a,b;
    public :
    void set()
    {
        cin>>a>>b;
    }
    void get ()
    {
        cout<<a<<b;}
        friend int calculator::sumRealcomplex(complex o1,complex o2);

};
int calculator::sumRealcomplex(complex o1,complex o2) {
    return (o1.a+o2.a);
}
int main(){
    complex ob1,ob2,ob3;
    ob1.set();
}
   