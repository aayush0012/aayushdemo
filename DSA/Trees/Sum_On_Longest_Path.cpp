class Solution {
  public:
    void solve(Node*root, int sum, int&maxi ,int len , int &maxlen){
        if(root==NULL){
            if(len>maxlen){  // Most imp part 
                maxlen=len; 
                maxi=sum ;
            }
            else if(len==maxlen){ /// 
                maxi=max(maxi,sum ) ; 
            }
            return; 
        }
        sum=sum+root->data;
        solve(root->left,sum ,maxi,len+1,maxlen);
        solve(root->right,sum,maxi,len+1,maxlen); 
    }
    int sumOfLongRootToLeafPath(Node *root) {
        int maxi =-9999; 
        int maxlen=-999; 
        int sum=0 ;
        int len =-10 ; 
        solve(root,sum,maxi,len,maxlen);
        return maxi; 
        
    }
};
