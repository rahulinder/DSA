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

    void insert_beg(int data)
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
        head=newnode;
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

    void insert_after(int value,int data)
    {
        if(head==NULL)
        {
            cout<<"list empty\n";
            return;
        }
        node* temp=head;
        do
        {
            if(temp->data==value)
            {
                node* newnode=new node(data);
                newnode->next=temp->next;
                temp->next=newnode;
                return;
            }
            temp=temp->next;
        }
        while(temp!=head);
        cout<<"value not found\n";
    }

    void delete_value(int value)
    {
        if(head==NULL)
        {
            cout<<"list empty\n";
            return;
        }
        node* temp=head;
        node* prev=NULL;
        do
        {
            if(temp->data==value)
            {
                if(temp==head)
                {
                    node* last=head;
                    while(last->next!=head)
                    {
                        last=last->next;
                    }
                    if(head->next==head)
                    {
                        delete head;
                        head=NULL;
                        return;
                    }
                    last->next=head->next;
                    head=head->next;
                    delete temp;
                    return;
                }
                else
                {
                    prev->next=temp->next;
                    delete temp;
                    return;
                }
            }
            prev=temp;
            temp=temp->next;
        }
        while(temp!=head);
        cout<<"value not found\n";
    }

    void search(int value)
    {
        if(head==NULL)
        {
            cout<<"list empty\n";
            return;
        }
        node* temp=head;
        int pos=1;
        do
        {
            if(temp->data==value)
            {
                cout<<"found at position "<<pos<<"\n";
                return;
            }
            temp=temp->next;
            pos++;
        }
        while(temp!=head);
        cout<<"not found\n";
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
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        while(temp!=head);
        cout<<"(back to head)\n";
    }
};

int main()
{
    circularlist cl;
    int choice,data,value;
    do
    {
        cout<<"\n1. insert at beginning\n2. insert at end\n3. insert after\n4. delete value\n5. search\n6. display\n7. exit\n";
        cout<<"enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"enter data: ";
                cin>>data;
                cl.insert_beg(data);
                break;
            }
            case 2:
            {
                cout<<"enter data: ";
                cin>>data;
                cl.insert_end(data);
                break;
            }
            case 3:
            {
                cout<<"enter existing value: ";
                cin>>value;
                cout<<"enter new data: ";
                cin>>data;
                cl.insert_after(value,data);
                break;
            }
            case 4:
            {
                cout<<"enter value to delete: ";
                cin>>value;
                cl.delete_value(value);
                break;
            }
            case 5:
            {
                cout<<"enter value to search: ";
                cin>>value;
                cl.search(value);
                break;
            }
            case 6:
            {
                cl.display();
                break;
            }
            case 7:
            {
                cout<<"exiting...\n";
                break;
            }
            default:
            {
                cout<<"invalid choice\n";
            }
        }
    }
    while(choice!=7);
    return 0;
}
