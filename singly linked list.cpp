//singly linked list full implementation

#include<iostream>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node(int v)
    {
        val=v;
        next=NULL;
    }
};

void insert1(node *&head, node *&tail)
{
    cout<<"Enter value into linked list:";
    int val;
    cin>>val;
    node *temp=new node (val);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    cout<<"value is added "<<endl;
}
void insert2(node *&head, node *&tail)
{
    cout<<"Enter value into linked list:";
    int val;
    cin>>val;
    node *temp=new node (val);
    if(tail==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
    cout<<"value is added "<<endl;
}
void insert3(node *&head, node *&tail)
{
    cout<<"Enter value into linked list:";
    int val;
    cin>>val;
    node *temp=new node (val);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        cout<<"Enter position for this node :";
        int p;
        cin>>p;
        node *position=head;
        for(int i=0; i<p-2; i++)
        {
            position=position->next;
            if(position ==NULL)
            {
                cout<<"invalid position"<<endl;
                return;
            }
        }
        temp->next=position->next;
        position->next=temp;

    }
    cout<<"value is added "<<endl;
}
void delete1(node *&head,node *&tail)
{
    node *temp=head;
    if(head!=NULL)
    {
        head=head->next;
        delete temp;
    }

    if(head==NULL)
    {
        tail=NULL;
    }
    cout<<"head is deleted "<<endl;
}
void delete2(node *&head, node*&tail)
{
    if(head!=NULL && head->next!=NULL)
    {
        node *temp=head;
        node *temp1;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        delete temp;
        temp1->next=NULL;
        tail=temp1;
    }
    cout<<"tail is deleted "<<endl;
}
void delete3(node *&head,node*&tail)
{
    if(head!=NULL)
    {
        cout<<"Enter position of the node :";
        int p;
        cin>>p;
        if(p==1)
        {
            delete1(head,tail);
            return;
        }
        node *position=head;
        for(int i=0; i<p-2; i++)
        {
            position=position->next;
            if(position==NULL || position->next==NULL)
            {
                return;
            }
        }
        node *temp=position->next;
        if(temp==NULL)
        {
            return;
        }
        position->next=temp->next;
        delete temp;
        cout<<"preferred node is deleted "<<endl;
    }

}
void print1(node *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
}
void print2(node*head)
{
    if(head==NULL)
    {
        return;
    }
    else
    {
        cout<<head->val<<" ";
        print2(head->next);
    }
}
void print3(node*head)
{
    if(head==NULL)
    {
        return;
    }
    else
    {

        print3(head->next);
        cout<<head->val<<" ";
    }
}
void sort1(node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    for (node *i = head; i->next != NULL; i = i->next)
    {
        for (node *j = i->next; j != NULL; j = j->next)
        {
            if (i->val > j->val)
            {
                swap(i->val, j->val);
            }
        }
    }
}

int main()
{
    node *head=NULL;
    node *tail=NULL;
    cout<<"1.insert head 2.insert tail 3.insert pos 4.delete head 5. delete tail 6. delete pos 7.print 8.print(recurssion) 9.print(recurssion&reverse) 10.sort linked list"<<endl;
    while(1)
    {
        cout<<endl<<"enter your choiec :";
        int i;
        cin>>i;
        switch(i)
        {
        case 1:
        {
            insert1(head,tail);
        }
        break;
        case 2:
        {

            insert2(head,tail);
        }
        break;
        case 3:
        {
            insert3(head,tail);

        }
        break;
        case 4:
        {

            delete1(head,tail);
        }
        break;
        case 5:
        {

            delete2(head,tail);
        }
        break;
        case 6:
        {
            delete3(head,tail);
        }
        break;
        case 7:
        {
            print1(head);

        }
        break;
        case 8:
        {
            print2(head);
        }
        break;
        case 9:
        {
            print3(head);
        }
        break;
        case 10:
        {
            sort1(head);
        }
        break;
        default:
            cout<<"am i joking with you? (insert within range or get out of here) "<<endl;

        }
    }
}
