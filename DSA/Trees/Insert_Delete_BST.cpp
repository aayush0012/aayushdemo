#include<iostream>
using namespace std;
class Node{
public :
int data;
Node*left ;
Node*right; 
Node(int data){
    this->data=data;
    this->left =NULL ;
    this->right = NULL; 
}
}; 
Node* insert(Node*root,int val ) { 
    if(root==NULL){
      root = new Node(val) ;
      return root; 
    }
    if(val>root->data){
        root->right =insert(root->right,val); 
    }
    else{
        root->left = insert(root->left,val); 
    }

}
Node* minval(Node*root){ 
    Node*temp=root; 
    while(temp->left){
        temp=temp->left; 
    }
    return temp ;
}
Node*del(Node*root, int val ){ 
    if(root==NULL){
        return NULL ;
    }
    if(root->data==val){
        // ab 3 alg alg cases bnenge 
        // 1 case -> leaf node h 
        // 2 case-> parent node h but has 1 child 
        // 3 case ->parent node has 2 child 
        if(root->left==NULL && root->right==NULL){
            delete(root); 
            return NULL; 
        }
        if(root->left!=NULL && root->right==NULL ){
            Node*temp=root ->left ;
            delete(root); 
            return temp; 
        }
        if(root->right!=NULL && root->left==NULL ){
            Node*temp =root->right  ;
            delete(root) ;
            return temp ;
        }
        if(root->left!=NULL && root->right!=NULL){
            // here comes the concept of inorder pred and succ 
            // we will go with the concept of inorder succ one can also solve for pred 
            // we created a min val function to get the minimum value 
            int mini = minval(root->right)->data; 
            root->data=mini;
            root->right=del(root->right,mini); 
            return root ;
        }
    }
    else if(root->data>val){
        root->left=del(root->left,val) ;
        return root ;
    }
    else{
        root->right = del(root->right,val) ;
        return root; 
    }
}
