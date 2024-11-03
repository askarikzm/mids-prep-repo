// array based Implmentaion Of Stack
#include<iostream>
using namespace std;
class Stacks{
    private:
    int data;
    int top;
    int n;
    int *arr;
    public: 
    Stacks(int n){
        this->n=n;
        arr=new int[n];
        top=-1;
    }
    bool isfull(){
        if(top==n-1){
            return true;
        }
        else return false;
    }
    void  push(int x){
       if(isfull()){
          cout<<"Stack is overFlow condition meets"<<endl;
          return ;
       }
       else{
         this->top++;
         this->arr[top]=x; 
         cout<<"Push Suceesfully"<<endl;
       }
    }
    void pop(){
        if(this->top==-1){
            cout<<"Stack UnderFlow Condtions Meets"<<endl;
            return ;
        }
        else{
            top--;
        }
    }
    int gettop(){
        if(top>-1 && top<n){
            return this->arr[top];
        }
        else return INT_MIN; // minimum value Store in array
    }

};

int main()
{
    Stacks s1(5);
    s1.push(10);
    s1.push(11);
    s1.push(9);
    s1.push(8);
    s1.push(6);
    s1.push(0);
    cout<<s1.gettop()<<endl;
    s1.pop();
    
    return 0;
}