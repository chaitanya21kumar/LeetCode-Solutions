class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        int l=0;
        int r=0;
        int ans=0;
        unordered_set<char> st;
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