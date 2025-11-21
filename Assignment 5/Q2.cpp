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

    int count_key(int key)
    {
        int count=0;
        node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                count++;
            }
            temp=temp->next;
        }
        return count;
    }

    void delete_all(int key)
    {
        while(head!=NULL && head->data==key)
        {
            node* temp=head;
            head=head->next;
            delete temp;
        }
        node* curr=head;
        while(curr!=NULL && curr->next!=NULL)
        {
            if(curr->next->data==key)
            {
                node* del=curr->next;
                curr->next=curr->next->next;
                delete del;
            }
            else
            {
                curr=curr->next;
            }
        }
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
    int n,data,key;

    cout<<"enter number of elements: ";
    cin>>n;
    cout<<"enter the elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>data;
        l.insert_end(data);
    }

    cout<<"enter key to count and delete: ";
    cin>>key;

    int count=l.count_key(key);
    cout<<"count: "<<count<<"\n";

    l.delete_all(key);

    cout<<"updated linked list: ";
    l.display();

    return 0;
}
