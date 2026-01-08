class Solution {
public:
    int largestRectangleArea(vector<int>& h) {

        int n=h.size();
        vector<int> nse(n,-1),pse(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[i]<=h[st.top()]) st.pop();
            nse[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        while(st.size()) st.pop();

        for(int i=0;i<n;i++){
            while(!st.empty() && h[i]<=h[st.top()]) st.pop();
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        int ans=INT_MIN;
        int temp=0;
        for(int i=0;i<n;i++){
            int l=pse[i],r=nse[i];
            if(r==-1) r=n;
            temp=(r-l-1)*h[i];
            ans=max(ans,temp);
        }
        return ans;
        
    }
};