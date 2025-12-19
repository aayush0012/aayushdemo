 // here Instead of using the Concept of hd we use Vertical dist 
        // for both left and right subtree we increase the cd by 1 
        // at a particular vd the nodes which comes later is stored;  

class Solution {
  public:
    vector<int> rightView(Node *root) {
        map<int,int>mp ;
        vector<int>ans; 
        queue<pair<Node*,int>>q; 
        if(root==NULL){
            return ans; 
        }
        q.push(make_pair(root,0)); 
        while(!q.empty()){
           pair<Node*,int>temp= q.front() ;
           q.pop(); 
           Node*front=temp.first; 
           int vd=temp.second; 
           mp[vd]=front->data ;
           if(front->left){
               q.push(make_pair(front->left,vd+1)) ;
           }
           if(front->right){
               q.push(make_pair(front->right,vd+1)); 
           }
        }
        for(auto it:mp){
            ans.push_back(it.second); 
        }
        return ans; 
    }
};
