class Solution {
  public:
  int getmax(map<Node*,Node*>& mp,Node*root){
      queue<Node*>q; 
      q.push(root);
      map<Node*,int>vis;  //  we mark all the nodes that are visited so we dont count them again  
      vis[root]=1; 
      int ans=0; 
      while(!q.empty()){
          int size=q.size(); 
          int a=0; 
          for(int i =0; i<size; i++){
              Node*temp=q.front();
              q.pop(); 
              if(temp->left && !vis[temp->left]){
                  q.push(temp->left);  // CHECK FOR LEFT NODE IF ITS VISITED OR NOT 
                  vis[temp->left]=1; 
                  a=1; 
              }
              if(temp->right && !vis[temp->right]){
                  q.push(temp->right);  // SIMILAR FOR RIGHT NODE  
                  vis[temp->right]=1; 
                  a=1; 
              }
              if(mp[temp] && !vis[mp[temp]]){
                  a=1;
                  vis[mp[temp]]=1;  // HERE WE CHECK WHETHER THE PARENT NODE IS PRESENT AND IF YES THEN IS IT VISITED OR NOT 
                  q.push(mp[temp]); 
              }
          }
          if(a){
              ans++ ;
          }
      }
      return ans ; 
  }
  Node*mapping (Node*root , int target,  map<Node*,Node*>& mp){
     queue<Node*>q;
     q.push(root); 
     Node*res=NULL; 
     while(!q.empty()){
         Node*temp= q.front(); 
         q.pop(); 
         if(temp->data==target)res=temp ;
         if(temp->left){
             q.push(temp->left); 
             mp[temp->left]=temp; 
         }
         if(temp->right){
             q.push(temp->right); 
             mp[temp->right] = temp; 
         }
     }
     return res;
  }
    int minTime(Node* root, int target) {
        // code here
        map<Node*,Node*>mp; // using this we map root to its parent; 
        int time=0; 
        Node*start_Node=mapping(root,target, mp) ; 
        // startNode is the node from where we wil burn the tree
        // we used mapping func to map all nodes to their parent nodes
        int maxi=getmax(mp,start_Node); 
   return maxi; 
   
    }
};
