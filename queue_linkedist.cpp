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
class queues{
public:
node * front;
node * rear;
queues(){
    this->front=NULL;
    this->rear=NULL;
}
bool isempty()// check wether queue empty ot not
{ 
    return (this->rear==NULL);
}
void enque(int x){
    node * newnode=new node(x);
    if(this->rear==NULL){ // means nothing
        rear=front=newnode;
    }
    rear->next=newnode;
    rear=rear->next;
    cout<<"enque Successfully"<<endl;

}
void deque(){
    if(rear==front){
        rear=front=NULL; // shift back to orignal places :(
    }

    if(!isempty()){
        node * newnode=front;
        front=front->next;
        delete newnode;
    }
    else
    {
        cout<<"Condtion underflow!"<<endl;
    }
}
int gettop(){
    if(front!=NULL){
        return front->data;
        }
        else return INT16_MAX;
    
}

};

int main()
{
    queues q1;
    q1.enque(10);
    q1.enque(11);
    q1.enque(12);
    q1.enque(13);
    cout<<q1.gettop()<<endl;
    q1.deque();
    cout<<q1.gettop()<<endl;




    
    return 0;
}