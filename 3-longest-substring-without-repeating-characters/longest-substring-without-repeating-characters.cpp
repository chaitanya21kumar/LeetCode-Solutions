class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<char> st;
            int c=0;
            for(int j=i;j<n;j++){
                if(st.find(s[j])!=st.end()){
                    break;
                }
                c++;
                st.insert(s[j]);
                ans=max(ans,c);
            }
        }

        return ans;
        
    }
};