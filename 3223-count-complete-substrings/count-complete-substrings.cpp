class Solution {
public:
    int f(int s,int e,string &word,int k){
        int ans=0;
        for(int u=1;u<=26;u++){
            int wl=u*k;
            if(wl>e-s+1) break;
            vector<int> f(26,0);
            int gc=0; // good char count
            for(int i=s;i<s+wl;i++){
                int idx=word[i]-'a';
                f[idx]++;
                if(f[idx]==k) gc++;
                else if(f[idx]==k+1) gc--;
            }
            if(gc==u) ans++;
            for(int i=s+wl;i<=e;i++){
                int uci=word[i]-'a'; // upcoming char idx
                int oci=word[i-wl]-'a'; // outgoing char idx
                if(f[oci]==k+1) gc++;
                else if(f[oci]==k) gc--;
                f[oci]--;
                f[uci]++;
                if(f[uci]==k) gc++;
                else if(f[uci]==k+1) gc--;
                if(gc==u) ans++;
            }
        }
        return ans;
    }
    int countCompleteSubstrings(string word, int k) {

        int n=word.size();
        int ans=0;
        int lidx=0;
        for(int i=0;i<n;i++){
            if(i>0 && abs(word[i]-word[i-1])>2){
                ans+=f(lidx,i-1,word,k);
                lidx=i;
            }

        }
        ans+=f(lidx,n-1,word,k);
        return ans;
        
    }
};