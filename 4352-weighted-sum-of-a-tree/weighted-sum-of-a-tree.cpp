class Solution {
public:
    typedef long long int ll;
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        
        ll n=nums.size();
        ll h=1;
        vector<vector<ll>> c(n);
        for(int i=1;i<n;i++){
            c[parent[i]].push_back(i);
        }
        vector<ll> depth(n);
        queue<ll> q;
        q.push(0);
        depth[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &x:c[node]){
                depth[x]=depth[node]+1;
                h=max(h,depth[x]);
                q.push(x);
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=(nums[i]*(h-depth[i]+1));
        }
        return ans;

    }
};