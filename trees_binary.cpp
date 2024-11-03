#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};
Node* Create_Node(int data){ // refernce to newly node
    Node * newnode=new Node(data);
    return newnode;
}
int height(Node * root){
    if(!root){
        return 0;
    }
    else return 1+max(height(root->left),height(root->right));
}
void printlevel(Node * root,int level){
    if(!root) return;
    if(level==1){
        cout<<root->data<<" ";
    }
    else if (level>1){
        printlevel(root->left,level-1);
        printlevel(root->right,level-1);

    }
   
}
 void bfs(Node * root){
    int h=height(root); // gives root height checking from left and right ends
    for(int i=0;i<=h;i++){
        printlevel(root,i);
    }   
    }

void infix(Node * head){
    if(head==nullptr){
        return ;
    }
    else {
        infix(head->left);
        cout<<head->data<<" ";
        infix(head->right);
    }

}
void prefix(Node * head){
    if(head==nullptr){
        return ;
    }
    else {
        cout<<head->data<<" ";
        infix(head->left);
        infix(head->right);
    }

}

int main()
{
     Node * root=Create_Node(1); // level 0 parent Root Node
     root->left=Create_Node(2);
     root->right=Create_Node(3);
     root->left->left=Create_Node(4);
     root->left->right=Create_Node(5);
     cout<<height(root)<<endl;
     bfs(root);
     cout<<endl;
     infix(root);
     cout<<endl;
     prefix(root);
    return 0;
}