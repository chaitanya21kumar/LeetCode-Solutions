class Solution {
public:
    int f(int mid,int p,vector<int>& nums){

        int n=nums.size();
        int c=0;
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])<=mid){
                c++;
                i++;
            }
        }
        if(c>=p) return true;
        return false;

    }
    int minimizeMax(vector<int>& nums, int p) {

        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        if(p==0) return 0;
        if(n==1) return nums[0];
        int lo=INT_MAX; // min diff
        int hi=abs(nums[0]-nums[n-1]); // max diff

        for(int i=0;i<n-1;i++){
            lo=min(lo,abs(nums[i]-nums[i+1]));
        }

        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(f(mid,p,nums)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
};