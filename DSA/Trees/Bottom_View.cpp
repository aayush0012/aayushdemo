//Bottom View 
//Concept->  very similar to top view just keep on mapping map will auto take the bottom most value 

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int>ans;
        if(root==NULL){
            return ans  ; 
        }
        map<int,int>mp; 
        queue<pair<Node*,int>>q; 
        q.push(make_pair(root,0)); 
        while(!q.empty()){
            pair<Node*,int>temp= q.front() ;
            Node*back =temp.first; 
            q.pop(); 
            int hd=temp.second; 
            mp[hd]=back->data; // only diff where it differs from top view 
            if(back->left){
                q.push(make_pair(back->left,hd-1)); 
            }
            if(back->right){
                q.push(make_pair(back->right,hd+1)); 
            }
        }
        for(auto it:mp){
            ans.push_back(it.second); 
        }
        return ans ; 
        
    }
};
