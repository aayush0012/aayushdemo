class Solution {
public:
 vector<int> nextsmall(vector<int>& arr) {
         int n=arr.size() ;
        vector<int>ans(n,-1) ;
        stack<int>st; 
        for(int i=n-1; i>=0; i--){
                if(i==n-1 ){
                    st.push(i); 
                    continue; 
                }
            while(!st.empty()){
                int peek=st.top(); 
                if(arr[peek]<arr[i]){
                    ans[i]=peek ;
                    st.push(i); 
                     break ; 
                }
                else{
                st.pop(); 
                }
            }
            if(st.empty()){
                st.push(i); 
            }
        }
        return ans; 
    }
 vector<int> prevsmall(vector<int>& arr) {

         int n=arr.size() ;
        vector<int>ans(n,-1) ;
        stack<int>st; 
        for(int i=0; i<n; i++){
                if(i==0 ){
                    st.push(i); 
                    continue; 
                }
            while(!st.empty()){
                int peek=st.top(); 
                if(arr[peek]<arr[i]){
                    ans[i]=peek ;
                    st.push(i); 
                     break ; 
                }
                else{
                st.pop(); 
                }
            }
            if(st.empty()){
                st.push(i); 
            }
        }
        return ans; 
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next; 
        vector<int>prev; 
        next=nextsmall(heights); 
        prev=prevsmall(heights); 
        int max_area=INT_MIN;
        for(int i =0; i<heights.size() ;i++){
            int n= next[i]; 
            int p=prev[i] ;
            int h= heights[i] ;
            if(n==-1){
                n=heights.size(); 
            }
            int w=n-p-1; 
            max_area=max(max_area,h*w); 
        }
        return max_area; 
    }
};
