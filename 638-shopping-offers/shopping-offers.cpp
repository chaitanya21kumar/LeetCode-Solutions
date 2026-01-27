class Solution {
public:
    map<vector<int>,int> memo;
    int f(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        if(memo.count(needs)) return memo[needs];
        int ans=0;
        for(int i=0;i<price.size();i++){
            ans+=(price[i]*needs[i]);
        }
        for(auto &x:special){
            vector<int> next_needs=needs;
            bool offer_valid=true;
            for(int i=0;i<needs.size();i++){
                if(x[i]>needs[i]){
                    offer_valid=false;
                    break;
                }
                next_needs[i]-=x[i];
            }
            if(offer_valid){
                ans=min(ans,x.back()+f(price,special,next_needs));
            }
        }
        return memo[needs]=ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return f(price,special,needs);
    }
};