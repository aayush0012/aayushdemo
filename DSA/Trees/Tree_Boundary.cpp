
// PROBLEM-> Boundary Traversal 


class Solution {
  public:
  
  void solve(Node* root, vector<int>& arr) {
      if(root == NULL) return;

      solve(root->left, arr);
      if(root->left == NULL && root->right == NULL)
          arr.push_back(root->data);
      solve(root->right, arr);
  }

  vector<int> boundaryTraversal(Node *root) {
      vector<int>ans; 
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data) ; 
    // Now we go left and store all the leftmost non leaf nodes 
    Node*temp=root->left; 
    while(temp && (temp->left||temp->right)){
        ans.push_back(temp->data) ;
        if(temp->left){
            temp=temp->left; 
        }
        else{
            temp=temp->right; 
        }
    }
    // we have find all the non leaf nodes to the right now we go to all the leaf nodes
    solve(root->left,ans) ; // here we now push all the leaf node present on the left subtree and then right 
    solve(root->right,ans); 
    Node*val=root->right; 
    vector<int>arr; 
    while(val  && (val->right || val->left)){
            arr.push_back(val->data); 
            if(val->right){
                val=val->right; 
            }
            else{
                val=val->left ;
            }
    }
      reverse(arr.begin(), arr.end()); // as we have to display the right non leaf nodes from bottom to top so we reverse the array 
      for(int x : arr) ans.push_back(x);

      return ans;
  }
};
