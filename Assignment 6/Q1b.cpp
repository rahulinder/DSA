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

    void insert_beg(int data)
    {
        node* newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            return;
        }
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
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

    void insert_after(int value,int data)
    {
        node* temp=head;
        while(temp!=NULL && temp->data!=value)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"value not found\n";
            return;
        }
        node* newnode=new node(data);
        newnode->next=temp->next;
        newnode->prev=temp;
        if(temp->next!=NULL)
        {
            temp->next->prev=newnode;
        }
        temp->next=newnode;
    }

    void insert_before(int value,int data)
    {
        if(head==NULL)
        {
            cout<<"list empty\n";
            return;
        }
        if(head->data==value)
        {
            insert_beg(data);
            return;
        }
        node* temp=head;
        while(temp!=NULL && temp->data!=value)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"value not found\n";
            return;
        }
        node* newnode=new node(data);
        newnode->next=temp;
        newnode->prev=temp->prev;
        temp->prev->next=newnode;
        temp->prev=newnode;
    }

    void delete_value(int value)
    {
        if(head==NULL)
        {
            cout<<"list empty\n";
            return;
        }
        node* temp=head;
        if(temp->data==value)
        {
            head=head->next;
            if(head!=NULL)
            {
                head->prev=NULL;
            }
            delete temp;
            return;
        }
        while(temp!=NULL && temp->data!=value)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"value not found\n";
            return;
        }
        if(temp->next!=NULL)
        {
            temp->next->prev=temp->prev;
        }
        if(temp->prev!=NULL)
        {
            temp->prev->next=temp->next;
        }
        delete temp;
    }

    void search(int value)
    {
        node* temp=head;
        int pos=1;
        while(temp!=NULL)
        {
            if(temp->data==value)
            {
                cout<<"found at position "<<pos<<"\n";
                return;
            }
            temp=temp->next;
            pos++;
        }
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
    doublylist dl;
    int choice,data,value;
    do
    {
        cout<<"\n1. insert at beginning\n2. insert at end\n3. insert after\n4. insert before\n5. delete value\n6. search\n7. display\n8. exit\n";
        cout<<"enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"enter data: ";
                cin>>data;
                dl.insert_beg(data);
                break;
            }
            case 2:
            {
                cout<<"enter data: ";
                cin>>data;
                dl.insert_end(data);
                break;
            }
            case 3:
            {
                cout<<"enter existing value: ";
                cin>>value;
                cout<<"enter new data: ";
                cin>>data;
                dl.insert_after(value,data);
                break;
            }
            case 4:
            {
                cout<<"enter existing value: ";
                cin>>value;
                cout<<"enter new data: ";
                cin>>data;
                dl.insert_before(value,data);
                break;
            }
            case 5:
            {
                cout<<"enter value to delete: ";
                cin>>value;
                dl.delete_value(value);
                break;
            }
            case 6:
            {
                cout<<"enter value to search: ";
                cin>>value;
                dl.search(value);
                break;
            }
            case 7:
            {
                dl.display();
                break;
            }
            case 8:
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
    while(choice!=8);
    return 0;
}
