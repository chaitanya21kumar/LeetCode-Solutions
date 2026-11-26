class Solution {
public:
    int countPrimeSetBits(int l, int r) {

        int ans=0;
        unordered_set<int> s={2,3,5,7,11,13,17,19,23};
        for(int i=l;i<=r;i++){
            int x=__builtin_popcount(i);
            if(s.find(x)!=s.end()) ans++;
        }
        return ans;
        
    }
};