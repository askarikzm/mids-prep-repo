#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
   
};
class Stacks{
    private:
    Node * top;
    Node * head;
    public:
    Stacks(){
        this->top=NULL;
    }
   bool isempty(){
         return (top==NULL);
    }
    void push(int x){
        Node * newnode =new Node(x);
        if(top==NULL){
            top=newnode;
        }
        else{
           newnode->next=top;
           top=newnode;
        }
        cout<<"Data Being Pushed SucessFully"<<endl;
    }
    void pop(){
        if(!isempty()){
            Node * temp=top;
            top=top->next;
            cout<<"item is popped :\t"<<temp->data<<endl;
            delete temp;
        }
        else{
            cout<<"Underflow Condition!"<<endl;
        }
    }
    int gettop(){
        if(!isempty()){
            return  top->data;
        }
        else return INT_MIN;
    }

};

int main()
{
    Stacks s1;
    s1.push(10);
    s1.push(12);
    s1.push(13);
    s1.push(15);
    s1.pop();
    s1.pop();
    cout<<s1.gettop()<<endl;
    
    return 0;
}