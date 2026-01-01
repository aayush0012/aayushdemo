// User function Template for C++ 
//SOLVED THIS QUESTION USING RECURSION O(N) S.C AND O(N) T.C 
// WE CAN ALSO SOLVE THIS QUESTION USING MORRIS TRAVERSAL WHICH INLCUDES O(1) SPACE AND O(N) TIME 

class Solution {
  public:
   void solve(Node*root,Node* &prev){
       if(root==NULL){
            return ;
        }
       solve(root->right,prev); 
       solve(root->left,prev );
       root->right=prev; 
       root->left=NULL ;
       prev = root ; 
       return; 
   }
    void flatten(Node *root) {
        // we  can solve this questions using morris trav and recursion aswell 
        // recursion takes O(n) space and morris traversal takes O(1); 
        //USING RECURSION 
        Node*prev=NULL ;
        solve(root,prev); 
        return ;  
    }
    
    // 
};
