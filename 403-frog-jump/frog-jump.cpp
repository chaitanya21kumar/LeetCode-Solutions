class Solution {
public:
    typedef long long int ll;
    bool f(int i,int k,int n,vector<int>& stones,map<pair<ll,ll>,ll> &dp,unordered_map<ll,ll> &m){
        if(i==n-1) return true;
        if(i>=n) return false;
        if(dp.find({i,k})!=dp.end()) return dp[{i,k}];
        bool p1=false;
        bool p2,p3,p4;
        p2=p3=p4=false;
        if(i==0){
            ll t=stones[0]+1;
            if(m.find(t)!=m.end()){
                p1|=f(m[t],1,n,stones,dp,m);
            }
        }
        else{
            if(k-1>0){
                ll t=stones[i]+k-1;
                if(m.find(t)!=m.end()){
                    p2|=f(m[t],k-1,n,stones,dp,m);
                }
            }
            ll t1=stones[i]+k;
            if(m.find(t1)!=m.end()){
                p3|=f(m[t1],k,n,stones,dp,m);
            }
            ll t2=stones[i]+k+1;
            if(m.find(t2)!=m.end()){
                p4|=f(m[t2],k+1,n,stones,dp,m);
            }
        }
        return dp[{i,k}]=p1|p2|p3|p4;
    }
    bool canCross(vector<int>& stones) {

        int n=stones.size();
        unordered_map<ll,ll> m;
        map<pair<ll,ll>,ll> dp;
        for(int i=0;i<n;i++){
            m[stones[i]]=i;
        }
        return f(0,1,n,stones,dp,m);
        
    }
};