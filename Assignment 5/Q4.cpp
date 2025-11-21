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

    void reverse()
    {
        node* prev=NULL;
        node* curr=head;
        node* next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
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
        cout<<"->NULL\n";
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

    cout<<"original linked list: ";
    l.display();

    l.reverse();

    cout<<"reversed linked list: ";
    l.display();

    return 0;
}
