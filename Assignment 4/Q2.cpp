#include <iostream>
using namespace std;
//1 2 3 4 5 6 7
class queue{
  
  public:
  int front;
  int rear;
  int len;
  int* q;
  queue(int size){
      len=size;
      q=new int[len];
      front=-1;
      rear=-1;
  }
  bool isempty(){
      if(front== -1 && rear==-1){
          return true;
      }
      else
      return false;
  }
  bool isfull(){
      if(front==(rear+1)%len){
          return true;
      }
      else
      return false;
  }
  void enqueue(int val){
      if(isfull()){
          cout<<"Q is full"<<endl;
      }
      else{
          if(isempty()){
              front=0;
          }
          rear=(rear+1)%len;
          q[rear]= val;
      }
  }
  void dequeue(){
      if(isempty()){
          cout<<"Q is empty"<<endl;
      }
      else if(front==rear){
          front=rear=-1;
      }
      else{
         front=(front+1)%len;
      }
  }
  void display(){
      int i=front ;
      while(1){
          cout<<q[i]<<"  ";
          if(i==rear){
              break;
          }
          i=(i+1)%len;
      }
      cout<<endl;
  }
};
int main() {
    queue q1(10);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.display();
    

    return 0;
}