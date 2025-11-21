#include<iostream>
using namespace std;

class node
{
public:
    char data;
    node* next;
    node* prev;
    node(char data)
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

    void insert_end(char data)
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

    bool is_palindrome()
    {
        if(head==NULL)
        {
            return true;
        }
        node* start=head;
        node* end=head;
        while(end->next!=NULL)
        {
            end=end->next;
        }
        while(start!=end && end->next!=start)
        {
            if(start->data!=end->data)
            {
                return false;
            }
            start=start->next;
            end=end->prev;
        }
        return true;
    }

    void display()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data;
            if(temp->next!=NULL)
            {
                cout<<"<->";
            }
            temp=temp->next;
        }
        cout<<"\n";
    }
};

int main()
{
    doublylist l;
    int n;
    char ch;
    cout<<"enter number of characters: ";
    cin>>n;
    cout<<"enter characters:\n";
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        l.insert_end(ch);
    }
    cout<<"linked list: ";
    l.display();
    if(l.is_palindrome())
    {
        cout<<"it is a palindrome\n";
    }
    else
    {
        cout<<"not a palindrome\n";
    }
    return 0;
}
