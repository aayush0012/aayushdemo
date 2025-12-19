//Just need to store the left most node and ignore the rest node for that vertical level
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
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
           if(mp.find(vd)==mp.end()){
            mp[vd]=front->data ;
           }
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
