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

    void insert_beg(int data)
    {
        node* newnode=new node(data);
        newnode->next=head;
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
    }

    void insert_between(int data,int value,bool after=true)
    {
        if(head==NULL)
        {
            cout<<"list is empty\n";
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
        if(after)
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
        else
        {
            if(temp==head)
            {
                newnode->next=head;
                head=newnode;
                return;
            }
            node* prev=head;
            while(prev->next!=temp)
            {
                prev=prev->next;
            }
            prev->next=newnode;
            newnode->next=temp;
        }
    }

    void delete_beg()
    {
        if(head==NULL)
        {
            cout<<"list is empty\n";
            return;
        }
        node* temp=head;
        head=head->next;
        delete temp;
    }

    void delete_end()
    {
        if(head==NULL)
        {
            cout<<"list is empty\n";
            return;
        }
        if(head->next==NULL)
        {
            delete head;
            head=NULL;
            return;
        }
        node* temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }

    void delete_value(int value)
    {
        if(head==NULL)
        {
            cout<<"list is empty\n";
            return;
        }
        if(head->data==value)
        {
            node* temp=head;
            head=head->next;
            delete temp;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL && temp->next->data!=value)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            cout<<"value not found\n";
            return;
        }
        node* del=temp->next;
        temp->next=del->next;
        delete del;
    }

    void search(int value)
    {
        node* temp=head;
        int pos=1;
        while(temp!=NULL)
        {
            if(temp->data==value)
            {
                cout<<"value found at position "<<pos<<"\n";
                return;
            }
            temp=temp->next;
            pos++;
        }
        cout<<"value not found\n";
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
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"null\n";
    }
};

int main()
{
    linkedlist l;
    int ch,data,value;
    bool after;
    do
    {
        cout<<"\n1. insert at beginning\n";
        cout<<"2. insert at end\n";
        cout<<"3. insert before/after a node\n";
        cout<<"4. delete from beginning\n";
        cout<<"5. delete from end\n";
        cout<<"6. delete a specific node\n";
        cout<<"7. search for a node\n";
        cout<<"8. display all nodes\n";
        cout<<"9. exit\n";
        cout<<"enter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                cout<<"enter data: ";
                cin>>data;
                l.insert_beg(data);
                break;
            }
            case 2:
            {
                cout<<"enter data: ";
                cin>>data;
                l.insert_end(data);
                break;
            }
            case 3:
            {
                cout<<"enter new data: ";
                cin>>data;
                cout<<"enter existing value: ";
                cin>>value;
                cout<<"insert after (1) or before (0): ";
                cin>>after;
                l.insert_between(data,value,after);
                break;
            }
            case 4:
            {
                l.delete_beg();
                break;
            }
            case 5:
            {
                l.delete_end();
                break;
            }
            case 6:
            {
                cout<<"enter value to delete: ";
                cin>>value;
                l.delete_value(value);
                break;
            }
            case 7:
            {
                cout<<"enter value to search: ";
                cin>>value;
                l.search(value);
                break;
            }
            case 8:
            {
                l.display();
                break;
            }
            case 9:
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
    while(ch!=9);
    return 0;
}
