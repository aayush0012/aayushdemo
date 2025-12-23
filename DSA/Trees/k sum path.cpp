

// 2 Methods -> 1) using Array (large Tc) 2) using hashmaps +prefix sum(best method) 
// similar to subarray sum equals k question 
class Solution {
  public:
  void solve(Node*root, int k , map<int,int> &mp, int &cnt,int&sum) {
     if(root==NULL){
         return ; 
     }
     sum+=root->data; 
    int remove=sum-k ; 
    cnt+=mp[remove] ;
    mp[sum]++ ;
    solve(root->left,k,mp,cnt,sum) ;
    solve(root->right,k,mp,cnt,sum) ;
     mp[sum]--;
     sum -= root->data;
  }
    int countAllPaths(Node *root, int k) {
        map<int,int>mp; 
        mp[0]=1; 
        int sum=0 ;
        int cnt=0 ;
       solve(root,k,mp,cnt ,sum ); 
       return cnt ; 
    }
};
