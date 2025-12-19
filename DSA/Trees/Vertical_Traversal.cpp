// Q->vertical Traversal
// concept->  horizontal distance from root node and bfs traversal and mapping them in a vector form 
class Solution {

  public:
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>>ans; 
       map<int, map<int,vector<int>>>mp; 
       // mp[hd][level]= vector 
       queue<pair<Node*,pair<int,int>>>q;
       //queue->pair(Node ,pair(hd,level)); 
       if(root==NULL){
           return ans ; 
       }
       q.push(make_pair(root,make_pair(0,0))); 
        while(!q.empty()){
            pair<Node*,pair<int,int>>temp=q.front(); 
            Node*front=temp.first ;
            q.pop(); 
            int hd = temp.second.first; 
            int lvl= temp.second.second; 
            mp[hd][lvl].push_back(front->data); 
            if(front->left){
                q.push(make_pair((front->left),make_pair(hd-1,lvl+1)) );
            }
            if(front->right){
                q.push(make_pair((front->right),make_pair(hd+1,lvl+1)));
            }
        }
        for(auto it:mp){
            vector<int>arr;
            for(auto j:it.second){
                for(auto k:j.second){
                    arr.push_back(k); 
                }
            }
            ans.push_back(arr); 
        }
        return ans;
    }
};
