class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int m=mat.size(),n=mat[0].size();
        int idx=-1,mx=INT_MIN;
        for(int i=0;i<m;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) c++;
            }
            if(c>mx){
                mx=c;
                idx=i;
            }
        }
        return {idx,mx};
        
    }
};