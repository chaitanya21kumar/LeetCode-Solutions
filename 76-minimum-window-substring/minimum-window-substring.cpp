class Solution {
public:
    string minWindow(string s, string t) {

        int n1=s.size(),n2=t.size();
        int l=0,r=0,c=0,idx=-1,mn=INT_MAX;
        vector<int> v(256,0);

        for(int i=0;i<n2;i++) v[t[i]]++;

        while(r<n1){
            if(v[s[r]]>0) c++;
            v[s[r]]--;

            while(c==n2){
                if(mn>r-l+1){
                    mn=r-l+1;
                    idx=l;
                }
                v[s[l]]++;
                if(v[s[l]]>0) c--;
                l++;

            }
            
            r++;
        }

        if(idx==-1) return "";
        return s.substr(idx,mn);
        
    }
};