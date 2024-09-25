//singly linked list full implementation

#include<iostream>
#include<vector>
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
void insert1(node *&head , node *&tail){
cout<<"Enter value into linked list:";
int val;
cin>>val;
node *temp=new node (val);
if(head==NULL){
    head=temp;
    tail=temp;
}
else{
    temp->next=head;
    head=temp;
}
cout<<"value is added "<<endl;
}
void insert2(node *&head , node *&tail){
cout<<"Enter value into linked list:";
int val;
cin>>val;
node *temp=new node (val);
if(head==NULL){
    head=temp;
    tail=temp;
}
else{
    tail->next=temp;
    tail=temp;
}
cout<<"value is added "<<endl;
}
void insert3(node *&head , node *&tail){
cout<<"Enter value into linked list:";
int val;
cin>>val;
node *temp=new node (val);
if(head==NULL){
    head=temp;
    tail=temp;
}
else{
        cout<<"Enter position for this node :";
        int p;
        cin>>p;
        node *position=head;
        for(int i=0;i<p-2;i++){
            position=position->next;
            if(position->next==NULL){
                return;
            }
        }
        temp->next=position->next;
        position->next=temp;

}
cout<<"value is added "<<endl;
}
void delete1(node *&head){
node *temp=head;
if(head!=NULL){
    head=head->next;
    delete temp;
}
cout<<"head is deleted "<<endl;
}
void delete2(node *head){

if(head!=NULL){
    node *temp=head;
        while(temp->next->next!=NULL){
    temp=temp->next;}
    node *temp1=temp->next;
    delete temp1;
    temp->next=NULL;
}
cout<<"tail is deleted "<<endl;
}
void delete3(node *head){

if(head!=NULL){
   cout<<"Enter position of the node :";
        int p;
        cin>>p;
        node *position=head;
        for(int i=0;i<p-2;i++){
            position=position->next;
            if(position->next==NULL){
                return;
            }
        }
        node *temp=position->next;
        position->next=temp->next;
        delete temp;
}
cout<<"preferrd node is deleted "<<endl;
}
void print1(node *head){
while(head!=NULL){
    cout<<head->val<<" ";
    head=head->next;
}
}
void print2(node*head){
if(head==NULL){
    return;
}
else{
    cout<<head->val<<" ";
    print2(head->next);
}
}
void print3(node*head){
if(head==NULL){
    return;
}
else{

    print3(head->next);
    cout<<head->val<<" ";
}
}

int main()
{
    node *head=NULL;
    node *tail=NULL;
    cout<<"1.insert head 2.insert tail 3.insert pos 4.delete head 5. delete tail 6. delete pos 7.print 8.print(r) 9.print(r&re)"<<endl;
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

delete1(head);
        }
        break;
        case 5:
        {

delete2(head);
        }
        break;
        case 6:
        {
delete3(head);
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
        default:
            cout<<"am i joking with you? (insert within range or get out of here) "<<endl;

        }
    }
}
