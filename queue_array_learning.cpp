#include<iostream>
using namespace std;
class queues{
    private:
    int rear;
    int front;
    int  size;
    int  *arr;
    public:
    queues(int size){
        this->size=size;
        this->arr=new int[size];
        this->front=this->rear=-1; // intailty both are at zero
    }
    bool isfull(){
        return (this->rear+1)%this->size==front; // mean rear at end front at zero
    }
    bool isempty(){
        return front==-1;
    }
    void enque(int x){
        if(isfull()){
            cout<<"Queue is already Fulled"<<endl;
            return ;
        }
        if(isempty()){
                rear=front=0; // make both pointers Zero
            }
            else{
                this->rear=(this->rear+1)%size;
            }
            this->arr[this->rear]=x;
            cout<<"Enque Sucessfully"<<endl;
            return ;
    }
    void deque(){
        if(isempty()){
            cout<<"Queue is already Empty"<<endl;
            return;
        }
        else{
            if(rear==front){
                rear=front=-1; // make again to start
            }
            else {
                front=(front+1)%size;
            }
            cout<<"Dequeue is SucessFully!"<<endl;
            return ;
        }
    }
    int gettop(){
        if(!isempty()){
            return arr[front];
        }
        else return INT16_MIN;
    }

};


int main()
{
    queues c1(4);
    c1.enque(5);
    c1.enque(4);
    c1.enque(3);
    c1.enque(2);
    c1.deque();
    c1.enque(6);
    c1.deque();
    c1.deque();
    c1.deque();
    cout<<c1.gettop();
    
    return 0;
}