class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> ans;
    vector<int> count;
    void f(int i,int p,string &labels){
        char ch=labels[i];
        int cb=count[ch-'a'];
        count[ch-'a']++;
        for(auto &x:adj[i]){
            if(x==p) continue;
            f(x,i,labels);
        }
        int ca=count[ch-'a'];
        ans[i]=ca-cb;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.assign(n,0);
        count.assign(26,0);
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        f(0,-1,labels);
        return ans;

    }
};