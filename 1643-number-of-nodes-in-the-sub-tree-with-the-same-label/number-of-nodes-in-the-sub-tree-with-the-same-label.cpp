class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> result;
    vector<int> f(int i,int par,int n,string &labels){
        vector<int> cur(26,0);
        int cur_char=labels[i];
        cur[cur_char-'a']=1;
        for(auto &x:adj[i]){
            if(x==par) continue;
            vector<int> child(26,0);
            child=f(x,i,n,labels);
            for(int i=0;i<26;i++){
                cur[i]+=child[i];
            }
        }
        result[i]=cur[cur_char-'a'];
        return cur;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        result.assign(n,0);
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        f(0,-1,n,labels);
        return result;
    }
};