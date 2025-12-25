// Here we used maps instead of using an array because it reduces time complexity of finding the pos from O(n) to O(1) 

class Solution {
  public:
  int posi(vector<int> &inorder ,int element,map<int,int>&mp){
      return mp[element] ; 
      
  } 
  Node* solve(vector<int> &inorder, vector<int> &preorder, int &index, int start,int end,map<int,int> &mp){
      //base case 
      if(index>=inorder.size() || start>end){
          return NULL ;
      }
     int element =preorder[index++]; 
     Node*root= new Node(element); 
     int pos = posi(inorder,element,mp); 
     root->left = solve(inorder,preorder,index,start ,pos-1,mp); 
     root->right= solve(inorder,preorder,index, pos+1, end,mp ) ;
     return root; 
  }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
       int index= 0 ;
        int start= 0; 
        int end= inorder.size(); 
        map<int,int>mp; 
        for(int i =0 ;i<inorder.size(); i++){ 
            mp[inorder[i]]=i ;
        } 
            
        Node*ans= solve(inorder , preorder , index, start ,end,mp) ;
        return ans ; 
        // to optimise we use maps 
    }
};
