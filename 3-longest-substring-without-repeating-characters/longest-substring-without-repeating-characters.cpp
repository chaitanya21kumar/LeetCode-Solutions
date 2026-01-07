class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        int l=0,r=0;
        map<int,int> m;
        int mx=0;
        int c=0;
        while(r<n){
            if(m[s[r]]==0){
                m[s[r]]++;
                c++;
            }
            else{
                while(m[s[r]]!=0){
                    m[s[l]]--;
                    if(m[s[l]]==0) m.erase(s[l]);
                    l++;
                    c--;
                }
                m[s[r]]++;
                c++;
            }
            mx=max(mx,c);
            r++;
        }
        return mx;
        
    }
};