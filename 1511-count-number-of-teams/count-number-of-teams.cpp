class Solution {
public:

    int n;
    vector<int> bit;
    void update(int id,int val){
        while(id<=n){
            bit[id]+=val;
            id+=(id&(-id));
        }
    }
    int query(int id){
        int ans=0;
        while(id>0){
            ans+=bit[id];
            id-=(id&(-id));
        }
        return ans;
    }
    int numTeams(vector<int>& rating) {
        n=rating.size();
        bit.assign(n+1,0);
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={rating[i],i};
        }
        sort(v.begin(),v.end());
        vector<int> ls(n),rs(n);
        for(auto &x:v){
            int idx=x[1];
            int id=idx+1;
            ls[idx]=query(id-1);
            rs[idx]=query(n)-query(id);
            update(id,1);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int nls=ls[i],nrs=rs[i];
            int nll=i-nls,nrl=n-1-i-nrs;
            ans+=(nls*nrl)+(nll*nrs);
        }
        return ans;
    }
};