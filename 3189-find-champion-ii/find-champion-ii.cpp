class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        vector<int> indeg(n);
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            indeg[v]++;
        }
        int c=0;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                c++;
                idx=i;
            }
        }
        return (c==1)?idx:-1;
        
    }
};