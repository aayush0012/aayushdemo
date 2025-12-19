class Solution {
  public:
    vector<int> topView(Node *root) {
        // we dont need level concept as bfs will auto take care 
        // we need to acces the first element accordign to bfs traversal
        // same concpet as vertical view Q but only take the first element of the array 
        
        vector<int>ans ; 
        map<int,int>mp ;
        queue<pair<Node*,int>>q ;
        if(root==NULL){
            return ans ; 
        }
        q.push(make_pair(root,0)); 
        while(!q.empty()) {
            pair<Node*,int>temp = q.front(); 
            q.pop(); 
            Node*front= temp.first ; 
            int hd = temp.second; 
            if(mp.find(hd)==mp.end()){
                // hd is not present in the map 
                mp[hd]=front->data; 
            }
            if(front->left){
                q.push(make_pair(front->left,hd-1));
            }
            if(front->right){
                q.push(make_pair(front->right,hd+1)); 
            }
        }
        for(auto it: mp){
            ans.push_back(it.second); 
        }
        return ans ; 
    }
       
};
