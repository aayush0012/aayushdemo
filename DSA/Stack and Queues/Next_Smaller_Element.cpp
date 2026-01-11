// Using Stacks we see the next smaller element Similar tasks can be done for next greater elemnet 
// Builds base for solving problems like Maximal Rectangle and Largest area in a histogram 
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
         int n=arr.size() ;
        vector<int>ans(n,-1) ;
        //now we start from the last element  
        stack<int>st; 
        for(int i=n-1; i>=0; i--){
                if(i==n-1 ){
                    st.push(arr[i]); 
                    continue; 
                }
            while(!st.empty()){
                int peek=st.top(); 
                if(peek<arr[i]){
                    ans[i]=peek ;
                    st.push(arr[i]); 
                     break ; 
                }
                else{
                st.pop(); 
                }
            }
            if(st.empty()){
                st.push(arr[i]); 
            }
        }
        return ans ; 
    }
};
