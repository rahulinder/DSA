#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class circularlist
{
    node* head;
public:
    circularlist()
    {
        head=NULL;
    }

    void insert_end(int data)
    {
        node* newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
            return;
        }
        node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"list empty\n";
            return;
        }
        node* temp=head;
        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        while(temp!=head);
        cout<<head->data<<"\n";
    }
};

int main()
{
    circularlist l;
    int n,data;
    cout<<"enter number of elements: ";
    cin>>n;
    cout<<"enter the elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>data;
        l.insert_end(data);
    }
    cout<<"output: ";
    l.display();
    return 0;
}
