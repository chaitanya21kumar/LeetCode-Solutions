class Solution {
public:
    typedef long long int ll;
    bool isv(char &ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
    ll f(string &word,ll k){
        ll c=0,v=0;
        vector<int> vv(26,0);
        ll l=0,r=0;
        ll ans=0;
        ll n=word.size();
        while(r<n){
            char ch=word[r];
            vv[ch-'a']++;
            if(isv(ch)){
                if(vv[ch-'a']==1)
                v++;
            }
            else c++;
            while(v==5 && c>=k){
                ans+=(n-r);
                vv[word[l]-'a']--;
                if(isv(word[l])){
                    if(vv[word[l]-'a']==0)
                    v--;
                }
                else c--;
                l++;
            }
            r++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {

        ll n=word.size();
        return f(word,k)-f(word,k+1);
        
    }
};