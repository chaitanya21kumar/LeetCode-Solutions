class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        int mn=INT_MAX;
        int mx=INT_MIN;
        int ans=0;
        for(int i=0;i<n;i++){
            if(prices[i]-mn>ans){
                ans=prices[i]-mn;
            }
            mn=min(mn,prices[i]);
        }
        return ans;
        
    }
};