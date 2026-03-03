class Solution {
public:
    typedef long long int ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {

        ll n=prices.size();
        ll i=0,j=0;
        ll top=0,wp=0,mp=0; // total org profit, window profit, modified profit
        for(int i=0;i<n;i++){
            top+=(ll)prices[i]*strategy[i];
        }
        ll mxg=0;
        while(j<n){
            wp+=prices[j]*strategy[j];
            if(j-i+1>k/2){
                mp+=prices[j];
            }
            if(j-i+1>k){
                wp-=prices[i]*strategy[i];
                mp-=prices[i+k/2];
                i++;
            }
            if(j-i+1==k){
                mxg=max(mxg,-wp+mp);
            }
            j++;
        }
        return top+mxg;
        
    }
};