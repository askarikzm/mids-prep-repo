// implementation of singly circular list
#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class circularlinkedlist{
    public:
    node * head;
    circularlinkedlist(){ // Creatition 
        head=NULL;
    }
    void insertion(int x){
        if(head==NULL){ // no node exsit
         node * newnode=new node(x);
         head=newnode;
         head->next=newnode; // both pointer and inside address are same
        }
        if(head->next==head){
            node * newnode=new node(x);
            head->next=newnode;
            newnode->next=head; // giving it address back to it
        }
        else{
            node * temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            node * newnode=new node(x);
            newnode->next=head;
            temp->next=newnode; 
        }
    }
   void display(){
     node * temp=head;
     do
     {
        cout<<temp->data<<"->\t";
        temp=temp->next;
     } while (temp->next!=head);
     cout<<"HEAD";
     
   }

};

int main()
{
    circularlinkedlist c1;
    c1.insertion(10);
    c1.insertion(20);
    c1.insertion(30);
    c1.insertion(40);
    c1.display();
    return 0;
}