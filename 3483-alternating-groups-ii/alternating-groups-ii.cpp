class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int N=colors.size();
        int n=N+k-1;
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int ans=0;
        int i=0,j=1;
        while(j<n){
            if(colors[j]==colors[j-1]){
                i=j;
                j++;
                continue;
            }
            if(j-i+1==k){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
        
    }
};