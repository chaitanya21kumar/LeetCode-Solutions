class Solution {
public:
    int minRotations(string s) {

        int n=s.size();
        int ans=0;
        int last=0;
        for(int i=0;i<n;i++){
            int x=s[i]-'0';
            ans+=min(abs(last-x),abs(10-abs(last-x)));
            last=x;
        }
        return ans;
        
    }
};