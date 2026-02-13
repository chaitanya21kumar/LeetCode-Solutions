class Solution {
public:
    typedef long long int ll;
    long long wonderfulSubstrings(string word) {

        int n=word.size();
        unordered_map<ll,ll> m;
        m[0]=1;
        ll cum_xor=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            int shift=word[i]-'a';
            cum_xor^=(1<<shift);
            ans+=m[cum_xor];
            for(char ch='a';ch<='z';ch++){
                int shift1=ch-'a';
                int odd_xor=cum_xor^(1<<shift1);
                ans+=m[odd_xor];
            }
            m[cum_xor]++;
        }
        return ans;
    }
};