class Solution {
public:
    bool poss(int k,vector<vector<int>> &p,int m,int n){

        int mnr=INT_MAX;
        int mxr=INT_MIN;

        int mnc=INT_MAX;
        int mxc=INT_MIN;

        for(int i=0;i+k<=m;i++){
            for(int j=0;j+k<=n;j++){

                int r=i+k-1;
                int c=j+k-1;
                int sum=p[r][c];
                if(i-1>=0){
                    sum-=p[i-1][c];
                }
                if(j-1>=0){
                    sum-=p[r][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    sum+=p[i-1][j-1];
                }
                if(sum==k*k){
                    mnr=min(mnr,i);
                    mxr=max(mxr,i);
                    mnc=min(mnc,j);
                    mxc=max(mxc,j);
                    if(mxr-mnr>=k || mxc-mnc>=k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {

        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> p(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                p[i][j]=mat[i][j];
                if(i>0){
                    p[i][j]+=p[i-1][j];
                }
                if(j>0){
                    p[i][j]+=p[i][j-1];
                }
                if(i>0 && j>0){
                    p[i][j]-=p[i-1][j-1];
                }
            }
        }
        int lo=1;
        int hi=min(m,n);
        int ans=0;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(poss(mid,p,m,n)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans*ans;
        
    }
};