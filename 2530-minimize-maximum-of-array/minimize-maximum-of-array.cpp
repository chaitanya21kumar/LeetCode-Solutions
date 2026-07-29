class Solution {
public:
    typedef long long int ll;
    bool poss(vector<int> &nums,int mid){
        ll excess=0;
        int n=nums.size();
        for(int i=n-1;i>=1;i--){
            ll cv=nums[i]+excess;
            if(cv>mid){
                excess=cv-mid;
            }
            else excess=0;
        }
        if(nums[0]+excess>mid) return false;
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {

        int n=nums.size();
        int lo=0;
        int hi=*max_element(nums.begin(),nums.end());
        int ans=hi;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(poss(nums,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
};