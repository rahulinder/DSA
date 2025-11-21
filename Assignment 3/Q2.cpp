#include <iostream>
#include <string>
using namespace std;

class stack{
	int top=-1;
	char s[30];
	public:
		void push(char ele){
			 	if(top==29){
		 cout<<"Stack full ! "<<endl;
				 }
 	   else{
		
 	        top++;
			s[top] =ele;
		}
	}
	void pop(){
		if(top ==-1){
			   	cout<<"Stack is empty already !"<<endl;
	   	        
		}
		 else{
		 	  
		 	   	top--;
    	        
		 }
	}
	bool isEmpty(){
		if(top==-1){
					return true;
		}
		 else 
		 return false;
	}
		void isFull(){
		if(top==29){
						cout<<"yes , Stack is full !"<<endl;
		}
		 else 
		 cout<<"noo , Stack is not full !"<<endl;
	}
	void display(){
		for(int i=0;i<=top;i++){
					cout<<s[i]<<" ";
		}
		 cout<<endl;
	}
	char peek(){
		if(top ==-1){
			   	return '-';
		}
		 else{
		 	   	return s[top];   	        
		 }
	}
};
int  main()
{
stack s1;
string ds="Data structure";
cout<<ds<<endl;
for(int i=0;i<ds.length();i++){
	s1.push(ds[i]);
}
s1.display();

string dsr="";
while(!s1.isEmpty()){
	dsr+=s1.peek();
	s1.pop();
}
cout<<dsr<<endl;

}