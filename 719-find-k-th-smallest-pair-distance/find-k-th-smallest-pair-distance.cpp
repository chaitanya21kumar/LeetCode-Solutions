class Solution {
public:
    int possible(vector<int>& nums,int d){
        int l=0,r=1,n=nums.size();
        int c=0;
        while(r<n){
            while(nums[r]-nums[l]>d) l++;
            c+=(r-l);
            r++;
        }
        return c;
    }
    int smallestDistancePair(vector<int>& nums, int k) {

        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        int lo=0,hi=nums[n-1]-nums[0];
        int ans=hi;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(possible(nums,mid)>=k){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
};