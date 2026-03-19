class Solution {
public:
    typedef long long int ll;
    int reverseBits(int n) {

        ll ans=0;
        for(int i=0;i<32;i++){
            ans<<=1;
            ll bit=n&1;
            ans|=bit;
            n>>=1;
        }
        return ans;

    }
};