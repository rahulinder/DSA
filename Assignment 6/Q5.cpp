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

class linkedlist
{
    node* head;
public:
    linkedlist()
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
    }

    void make_circular()
    {
        if(head==NULL)
        {
            return;
        }
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
    }

    bool is_circular()
    {
        if(head==NULL)
        {
            return false;
        }
        node* temp=head->next;
        while(temp!=NULL && temp!=head)
        {
            temp=temp->next;
        }
        if(temp==head)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    linkedlist l;
    int n,data;
    cout<<"enter number of elements: ";
    cin>>n;
    cout<<"enter elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>data;
        l.insert_end(data);
    }

    int choice;
    cout<<"make circular? (1 for yes, 0 for no): ";
    cin>>choice;
    if(choice==1)
    {
        l.make_circular();
    }

    if(l.is_circular())
    {
        cout<<"linked list is circular\n";
    }
    else
    {
        cout<<"linked list is not circular\n";
    }

    return 0;
}
