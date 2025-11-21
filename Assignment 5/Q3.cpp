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

    void find_middle()
    {
        if(head==NULL)
        {
            cout<<"list is empty\n";
            return;
        }
        node* slow=head;
        node* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<"middle element: "<<slow->data<<"\n";
    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"list is empty\n";
            return;
        }
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data;
            if(temp->next!=NULL)
            {
                cout<<"->";
            }
            temp=temp->next;
        }
        cout<<"\n";
    }
};

int main()
{
    linkedlist l;
    int n,data;

    cout<<"enter number of elements: ";
    cin>>n;
    cout<<"enter the elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>data;
        l.insert_end(data);
    }

    cout<<"linked list: ";
    l.display();

    l.find_middle();

    return 0;
}
