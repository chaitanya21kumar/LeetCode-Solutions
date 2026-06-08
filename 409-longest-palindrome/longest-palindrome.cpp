class Solution {
public:
    int longestPalindrome(string s) {

        int n=s.size();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        int ans=0;
        int o=0;
        for(auto &x:m){
            int f=x.second;
            ans+=(f/2)*2;
            if(f%2!=0){
                o=1;
            }
        }

        if(o==1) return ans+o;
        return ans;
        
    }
};