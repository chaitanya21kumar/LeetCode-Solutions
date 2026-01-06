class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();
        vector<int> lm(n),rm(n);

        int lmx=-1,rmx=-1;
        for(int i=0;i<n;i++){
            lm[i]=lmx;
            lmx=max(lmx,height[i]);
        }

        for(int i=n-1;i>=0;i--){
            rm[i]=rmx;
            rmx=max(rmx,height[i]);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int l=lm[i],r=rm[i];
            if(l==-1 || r==-1) continue;
            int x=(min(l,r)-height[i]);
            if(x>0) ans+=x;
        }

        return ans;
        
    }
};