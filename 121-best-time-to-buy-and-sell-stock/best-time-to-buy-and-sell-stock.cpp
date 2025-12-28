class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,n=prices.size();
        int amt=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<amt){
                amt=prices[i];
            }
            else if(prices[i]>amt){
                ans=max(ans,prices[i]-amt);
            }
        }

        return ans;
        
    }
};