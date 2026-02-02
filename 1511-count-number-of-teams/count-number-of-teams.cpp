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
        bit.resize(n+1,0);
        vector<int> ls(n,0),rs(n,0);
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={rating[i],i};
        }
        sort(v.begin(),v.end());
        for(auto &x:v){
            int idx=x[1];
            int id=idx+1;
            
            rs[idx]=query(n)-query(id);
            ls[idx]=query(id);
            update(id,1);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int nls=ls[i]; // number of left smaller
            int nrs=rs[i];
            int nll=i-nls; // number of left larger
            int nrl=n-1-i-nrs;
            ans+=(nls*nrl)+(nll*nrs);
        }
        return ans; 
    }
};