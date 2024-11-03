// array based Implementation Of Queue
#include<iostream>
using namespace std;
class queues{
    private:
    int rear;
    int front;
    int n;
    int *arr;
    public:
    queues(int n){
        this->n=n;
        arr=new int[n];
        front=-1;
        rear=-1;
    }
    bool isempty(){
        return front==-1;
    }
    bool isfull(){
        return (rear+1)%n==front; // if on last give true
    }
    void enquqe(int x){
        if(isfull()){
            cout<<"Queue is Full"<<endl;
            return ;
        }
        if(isempty()){
            front=rear=0;
        }
        else {
            rear=(rear+1)%n;
        }
        arr[rear]=x; // add element to queue
        cout<<"enqueued Sucessfully"<<endl;
    }
    void dequqe(){
        if(isempty()){
            cout<<"Queue is empty Already"<<endl;
        }
        else {
            if(front==rear){
                front=rear=-1; // if both are same
            }
            else {
                front=(front+1)%n;
            }
            cout<<"Dequqe SucessFully"<<endl;
        }
    }
    int gettop(){
        if(!isempty()){
            return this->arr[front];
        }
        else return INT16_MIN;
    }

};

int main()
{
    queues c1(4);
    c1.enquqe(5);
    c1.enquqe(4);
    c1.enquqe(3);
    c1.enquqe(2);
    c1.dequqe();
    c1.enquqe(6);
    c1.dequqe();
    c1.dequqe();
    c1.dequqe();
    cout<<c1.gettop();
    return 0;
}