#include <iostream>
using namespace std;

class stack{
	int top=-1;
	int s[10];
	public:
		void push(int ele){
			 	if(top==9){
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
	void isEmpty(){
		if(top==-1){
						cout<<"yes , Stack is empty !"<<endl;
		}
		 else 
		 cout<<"noo , Stack is not empty !"<<endl;
	}
		void isFull(){
		if(top==9){
						cout<<"yes , Stack is full !"<<endl;
		}
		 else 
		 cout<<"noo , Stack is not full !"<<endl;
	}
	void display(){
		for(int i=0;i<=top;i++){
					cout<<s[i]<<"  ";
		}
		 cout<<endl;
	}
	void peek(){
		if(top ==-1){
			   	cout<<"Stack is empty already !"<<endl;
		}
		 else{
		 	   	cout<< s[top];   	        
		 }
	}
};
int  main()
{
stack s1;
s1.isEmpty();
s1.push(6);
s1.push(88);
s1.push(63);
s1.push(48);
s1.push(61);
s1.push(8);
s1.display();
s1.peek();
}