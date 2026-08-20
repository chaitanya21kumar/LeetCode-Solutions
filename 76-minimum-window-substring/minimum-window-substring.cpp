class Solution {
public:
    string minWindow(string s, string t) {

        int n1=s.size();
        int n2=t.size();
        if(n2>n1) return "";
        int l=0,r=0,ans=INT_MAX,m=0;
        int idx=-1;
        unordered_map<char,int> h,n; // have, need
        for(int i=0;i<n2;i++){
            n[t[i]]++;
        }
        while(r<n1){
            h[s[r]]++;
            if(n[s[r]]>=h[s[r]]){
                m++;
            }
            while(m==t.size()){
                if(ans>r-l+1){
                    ans=r-l+1;
                    idx=l;
                }
                h[s[l]]--;
                if(n[s[l]]>h[s[l]]) m--;
                l++;
            }
            r++;
        }
        if(idx==-1) return "";
        return s.substr(idx,ans);
        
    }
};