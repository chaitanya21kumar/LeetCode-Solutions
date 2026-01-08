class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {

        int n=t.size();
        vector<int> nge(n,-1);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && t[i]>=t[st.top()]) st.pop();
            nge[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nge[i]==-1) ans[i]=0;
            else ans[i]=nge[i]-i;
        }

        return ans;
        
    }
};