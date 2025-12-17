Q-> Zig Zag Traversal 
Concept-> Level order traversal+ changing insertion direction either from front or back based on the level using boolean flags 


class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
            queue<Node*>q; // a queue to store all the nodes 
            bool flag=1; // use to detect left and right traversal
            vector<int>ans; 
            if(root==NULL){
                return ans ; //  if the root node is empty return ans as it is 
                
            }
            q.push(root); 
            while(!q.empty()){
                int size=q.size() ; 
                vector<int>arr(size) ;
                for(int i = 0; i<size; i++){
                    Node*temp=q.front(); 
                    q.pop(); 
                    int index =0; 
                    if(flag){
                        index=i; 
                    }
                    else{
                        index=size-i-1; 
                    }
                    arr[index]=temp->data ; 
                    if(temp->left){
                        q.push(temp->left) ;
                    }
                    if(temp->right){
                        q.push(temp->right) ;
                    }
                    
                }
                flag=!flag ; 
                for(auto it:arr){
                    ans.push_back(it); 
                }
            }
             return ans; 
        }
        
        
    
};
