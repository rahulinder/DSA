#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node* prev;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class doublylist
{
    node* head;
public:
    doublylist()
    {
        head=NULL;
    }

    void insert_end(int data)
    {
        node* newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }

    int size()
    {
        int count=0;
        node* temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
};

int main()
{
    doublylist l;
    int n,data;
    cout<<"enter number of elements: ";
    cin>>n;
    cout<<"enter elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>data;
        l.insert_end(data);
    }
    cout<<"size of doubly linked list: "<<l.size()<<"\n";
    return 0;
}
