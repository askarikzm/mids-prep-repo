// implementing breath first Search in Tress with three logic preorder,inorder and postorder
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node * Create_Node(int data){
    Node * newnode=new Node(data);
    return newnode;
}
// using preorder methhods
// void printdata(Node * root){
//     // base case 
//     if(root==nullptr){
//         return;
//     }
//     cout<<root->data<<endl;
//     printdata(root->left); // print left all
//     printdata(root->right); // using recursion 

// }
// preorder
void printdata(Node * root){
    // base case 
    if(root==nullptr){
        return;
    }
    printdata(root->left); 
    cout<<root->data<<endl;
    printdata(root->right); // using recursion 

}


int main()
{
   Node * root=Create_Node(1); // level 1 parent Root Node
    root->left=Create_Node(2);  // level 2 child 1 node
    root->right=Create_Node(3);  // level 3 child 3 node
    root->left->left=Create_Node(4);
    root->left->right=Create_Node(5);
    root->left->right->left=Create_Node(9);
    root->right->left=Create_Node(6);
    root->right->right=Create_Node(7);
    root->right->right->left=Create_Node(15);
    printdata(root);
    return 0;
}