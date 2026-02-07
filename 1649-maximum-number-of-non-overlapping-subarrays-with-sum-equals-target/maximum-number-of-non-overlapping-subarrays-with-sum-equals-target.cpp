class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {

        unordered_map<int,int> m;
        int n=nums.size();
        int l=0,r=0,s=0;
        m[0]=-1;
        int ans=0;
        int lidx=-1;
        while(r<n){
            s+=nums[r];
            int need=s-target;

            if(m.count(need)){
                if(m[need]>=lidx){
                    ans++;
                    lidx=r;
                }
            }
            m[s]=r;
            r++;
        }
        return ans;
        
    }
};