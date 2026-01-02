/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode* solve(TreeNode*root,TreeNode*p ,TreeNode*q){
    if(root==NULL){
        return NULL ;
    }
    if(root->val==p->val){
        return p ;
    }
    if(root->val==q->val){
        return q ; 
    }
    TreeNode*leftans = solve(root->left,p,q); 
    TreeNode*rightans=solve(root->right,p,q); 
    if(leftans==NULL &&rightans==NULL){
        return NULL ;
    }
    if(leftans!=NULL && rightans==NULL ){
            return leftans ; 
    }
    if(rightans!=NULL && leftans==NULL){
        return rightans ; 
    }
    return root; 
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*ans =solve(root,p,q); 
        return ans; 
    }
};
