 // same as making tree from inorder and preorder but we start iterating frome end of the posorder and assign right subtree values first
class Solution {
  public:
   int posi(vector<int> &inorder ,int element,map<int,int>&mp){
      return mp[element] ; 
      
  } 
  Node* solve(vector<int> &inorder, vector<int> &postorder, int &index, int start,int end,map<int,int> &mp){
      //base case 
      if(index<0|| start>end){
          return NULL ;
      }
     int element =postorder[index--]; 
     Node*root= new Node(element); 
     int pos = posi(inorder,element,mp); 
     root->right= solve(inorder,postorder,index, pos+1, end,mp ) ;
      root->left = solve(inorder,postorder,index,start ,pos-1,mp);
     return root; 
  }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int index= postorder.size()-1 ;
        int start= 0; 
        int end= inorder.size()-1; 
      
        map<int,int>mp; 
        for(int i =0 ;i<inorder.size(); i++){ 
            mp[inorder[i]]=i ;
        } 
         Node*ans= solve(inorder , postorder , index, start ,end,mp) ;
        return ans ; 
    }
};
