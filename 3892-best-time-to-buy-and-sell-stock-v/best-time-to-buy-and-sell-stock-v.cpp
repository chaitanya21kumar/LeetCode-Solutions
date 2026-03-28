class Solution {
public:
    typedef long long int ll;
    ll dp[1010][510][3][3];
    ll f(int i,vector<int>& prices,int n,int k,int b,int s){
        if(i>=n){
            if(b==0 || s==0) return -1e15;
            return 0;
        }
        if(dp[i][k][b][s]!=-1) return dp[i][k][b][s];
        ll nt=-1e15,st=-1e15,sk=-1e15;
        if(b==1 && s==1 && k>0){
            ll x=f(i+1,prices,n,k,0,s);
            if(x!=-1e15){
                nt=-prices[i]+x;
            }
        }
        else if(b==0){
            ll x=f(i+1,prices,n,k-1,1,s);
            if(x!=-1e15){
                nt=prices[i]+x;
            }
        }
        if(b==1 && s==1 && k>0){
            ll x=f(i+1,prices,n,k,b,0);
            if(x!=-1e15){
                st=prices[i]+x;
            }
        }
        else if(s==0){
            ll x=f(i+1,prices,n,k-1,b,1);
            if(x!=-1e15){
                st=-prices[i]+x;
            }
        }
        sk=f(i+1,prices,n,k,b,s);
        return dp[i][k][b][s]=max({nt,st,sk});
    }
    long long maximumProfit(vector<int>& prices, int k) {

        ll n=prices.size();
        memset(dp,-1,sizeof(dp));
        return f(0,prices,n,k,1,1);
        
    }
};