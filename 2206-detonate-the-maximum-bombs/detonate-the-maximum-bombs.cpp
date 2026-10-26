class Solution {
public:
    typedef long long int ll;
    void dfs(int i,unordered_set<int> &s,vector<vector<int>> &adj){
        s.insert(i);
        for(auto &y:adj[i]){
            if(s.find(y)==s.end()){
                dfs(y,s,adj);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                ll xi=bombs[i][0];
                ll yi=bombs[i][1];
                ll ri=bombs[i][2];

                ll xj=bombs[j][0];
                ll yj=bombs[j][1];
                ll rj=bombs[j][2];

                ll dbcsq=(xi-xj)*(xi-xj)+(yi-yj)*(yi-yj);
                if(ri*ri>=dbcsq){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int> s;
            dfs(i,s,adj);
            int x=s.size();
            ans=max(ans,x);
        }
        return ans;
        
    }
};