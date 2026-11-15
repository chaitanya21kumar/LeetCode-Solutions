class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<int> id(n);
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            id[v]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(id[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};