class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int n=strs.size();
        int l=strs[0].size();
        vector<int> sorted(n-1,0);
        int ans=0;
        for(int i=0;i<l;i++){
            int col_safe=1;
            for(int j=0;j<n-1;j++){
                if(!sorted[j] && strs[j][i]>strs[j+1][i]){
                    col_safe=0;
                    break;
                }
            }
            if(!col_safe) ans++;
            else{
                for(int k=0;k<n-1;k++){
                    if(!sorted[k] && strs[k][i]<strs[k+1][i]){
                        sorted[k]=1;
                    }
                }
            }

        }
        return ans;
        
    }
};