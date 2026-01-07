class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.size();
        int l=0,r=0,mxf=0,ans=0;
        map<char,int> m;

        while(r<n){
            m[s[r]]++;
            mxf=max(mxf,m[s[r]]);
            int len=r-l+1;
            if(len-mxf<=k){
                ans=max(ans,len);
            }
            else{
                while(len-mxf>k){
                    m[s[l]]--;
                    l++;
                    len=r-l+1;
                }
            }
            r++;
        }
        return ans;
        
    }
};