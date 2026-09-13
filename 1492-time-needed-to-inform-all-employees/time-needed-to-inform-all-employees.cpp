class Solution {
public:
    int f(int id,vector<vector<int>> &adj,vector<int>& it){
        int mxst=0; // max subord time
        for(auto &x:adj[id]){
            mxst=max(mxst,f(x,adj,it));
        }
        return it[id]+mxst;
    }
    int numOfMinutes(int n, int hid, vector<int>& manager, vector<int>& informTime) {

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        return f(hid,adj,informTime);
        
    }
};