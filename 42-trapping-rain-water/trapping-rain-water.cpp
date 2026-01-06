class Solution {
public:
    int trap(vector<int>& h) {

        int n=h.size();
        int lmx=0,rmx=0,l=0,r=n-1;
        int ans=0;
        while(l<r){
            if(h[l]>=h[r]){
                if(h[r]>rmx) rmx=h[r];
                else ans+=rmx-h[r];
                r--;
            }
            else{
                if(h[l]>lmx) lmx=h[l];
                else ans+=lmx-h[l];
                l++;
            }
        }

        return ans;
        
    }
};