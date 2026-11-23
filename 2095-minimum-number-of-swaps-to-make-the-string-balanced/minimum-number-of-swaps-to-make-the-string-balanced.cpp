class Solution {
public:
    int minSwaps(string s) {

        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
            }
        }
        return (st.size()+1)/2;
        
    }
};