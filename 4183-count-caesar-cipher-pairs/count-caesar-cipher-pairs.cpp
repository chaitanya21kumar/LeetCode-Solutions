class Solution {
public:
    typedef long long int ll;
    long long countPairs(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            string s=words[i];
            int sz=s.size();
            int shift=s[0]-'a';
            for(int j=0;j<sz;j++){
                int x=(words[i][j]-shift+26)%26;
                words[i][j]=x;
            }
            m[words[i]]++;
        }
        ll ans=0;
        for(auto x:m){
            ll k=x.second;
            ans+=(k*(k-1)/2);
        }
        return ans;
    }
};