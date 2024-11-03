#include<iostream>
using namespace std;
class node{
 public:
 int data;
 node * next;
 node  * prev;
node (int data){
    this->data=data;
    this->next=NULL;
    this->prev=NULL;
}
};
class doublylinked{
    public:
    node * head;
    node * tail;
    doublylinked(){
        this->head=NULL;
        this->tail=NULL;
    }    void insertion(int x){
        node * newnode=new node(x);
        node * temp=head;
         if(head==NULL){
            head=newnode;
            tail=newnode;
            head->next=head;
            head->prev=tail;
            return ;
        }
        if(head->next==head){
            tail=newnode;
            head->next=newnode;
            newnode->prev=head;
            newnode->next=head;
            head->prev=tail;
            return;
        }

        else{

        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        tail=newnode;
        tail->next=head;
        head->prev=tail;
        return ;
        }
    }
    void display(){
        node * temp=head;
        cout<<"<-\t";
        do
        {
            cout<<temp->data<<"\t<->\t";
            temp=temp->next;
        } while (temp!=head);
        cout<<"->tail-head"<<endl;
    }
};
int main()
{
    doublylinked l1;
    l1.insertion(10);
    l1.insertion(20);
    l1.insertion(30);
    l1.insertion(40);
   l1.display();
   if(l1.head->next->next->next->next==l1.head && l1.tail->next==l1.head){
    cout<<"Welcome to doubly world!"<<endl;
   }  
    return 0;
}