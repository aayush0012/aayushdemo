class Solution {
    void solve(vector<string>&ans,int idx,string s,int n){
        if(idx>=n){
            ans.push_back(s) ;
            return; 
        }
        // now we have two choices
        s[idx]='0'; 
        solve(ans,idx+1,s,n); 
        s[idx]='1';
        solve(ans,idx+1,s,n); 
        return; 
        
    }
  public:
    vector<string> binstr(int n) {
        // code here
        string s(n,'0'); 
        vector<string>ans; 
        solve(ans,0,s,n); 
        return ans; 
        
    }
};
