class Solution {
public:
    int longestSubstring(string s, int k) {

        int n=s.size();
        vector<int> f(26,0);
        for(int i=0;i<n;i++) f[s[i]-'a']++;
        for(int i=0;i<n;i++){
            if(f[s[i]-'a']<k){
                int left=longestSubstring(s.substr(0,i),k);
                while(i<n && f[s[i]-'a']<k) i++;
                int right=i<n?longestSubstring(s.substr(i),k):0;
                return max(left,right);
            }
        }
        return n;
        
    }
};