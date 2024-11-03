// implemetation of singly linked-list
#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node * next;
    node(int value){
        this->data=value;
        this->next=NULL; // currently at null
    }
};
class linkedlist{
    public:
    node * head;
    linkedlist(){
        this->head=NULL; 
    }
    void insert(int value){
        if(head==NULL){ // mean it is empty
            node * newnode=new node(value);
            head=newnode;
            return;
        }
        if(head->next==NULL){ // place in the Second to linked list
        node * newnode=new node(value);
        head->next=newnode;
        return ;
        }
        else{
            node * temp=head; // make a Shallow copy
            while(temp->next!=NULL){
                temp=temp->next;
            }
            node * newnode=new node(value);
            temp->next=newnode;
         return ;
        }
    }
    void display(){
        node * temp=head; 
        while (temp!=NULL)
        {
            cout<<temp->data<<"->\t";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        return;
    }
    void insert_at_k(int pos,int x){

        node * temp=head;
        int counter=1;
        while(counter!=(pos-1))
        {
            temp=temp->next;
            counter++;
        }
        node * newnode=new node(x);
        newnode->next=temp->next;
        temp->next=newnode;
        return ;
    }
    void deletion_at_k(int pos){
        node * temp=head;
        int counter=1;
        while(counter!=(pos-1))
        {
            temp=temp->next;
            counter++;
        }
        node * grabage=temp->next;
        temp->next=temp->next->next;
        delete grabage ;
        return ;
    }
    void updadtion(int x){
        node * temp=head;
        while (temp->next->data!=x)
        {
            temp=temp->next;
        }
        temp->next->data=-500;
        return;
    }
};

int main()
{
    linkedlist l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert_at_k(3,-1);
    l1.display();
    l1.deletion_at_k(3);
    l1.display(); 
    l1.updadtion(3);
    // update the value 3 in the code 
    l1.display();
    
    return 0;
}