class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        set<char> st;
        int l=0,r=0,ans=0;
        while(r<n){
            while(st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
        
    }
};