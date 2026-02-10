class Solution {
public:
    int f(int s,int e,string &word,int k){
        int ans=0;
        for(int u=1;u<=26;u++){
            int wl=u*k;
            if(wl>e-s+1) break;
            vector<int> f(26,0);
            int gc=0;
            for(int i=s;i<s+wl;i++){
                char ch=word[i]-'a';
                f[ch]++;
                if(f[ch]==k) gc++;
                else if(f[ch]==k+1) gc--;
            }
            if(gc==u) ans++;
            for(int i=s+wl;i<=e;i++){
                int upcoming_char_idx=word[i]-'a';
                int outgoing_char_idx=word[i-wl]-'a';
                if(f[outgoing_char_idx]==k) gc--;
                else if(f[outgoing_char_idx]==k+1) gc++;
                f[outgoing_char_idx]--;
                f[upcoming_char_idx]++;
                if(f[upcoming_char_idx]==k) gc++;
                else if(f[upcoming_char_idx]==k+1) gc--;
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