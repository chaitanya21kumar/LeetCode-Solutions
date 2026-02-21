class Solution {
public:
    int f1(vector<int>& nums,int n,int t){

        int lo=0,hi=n-1;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(nums[mid]==t){
                ans=mid;
                hi=mid-1;
            }
            else if(nums[mid]>t){
                hi=mid-1;
            }
            else if(nums[mid]<t){
                lo=mid+1;
            }
        }
        return ans;

    }
    int f2(vector<int>& nums,int n,int t){

        int lo=0,hi=n-1;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(nums[mid]==t){
                ans=mid;
                lo=mid+1;
            }
            else if(nums[mid]>t){
                hi=mid-1;
            }
            else if(nums[mid]<t){
                lo=mid+1;
            }
        }
        return ans;

    }

    vector<int> searchRange(vector<int>& nums, int t) {

        int n=nums.size();
        vector<int> ans;
        int s=f1(nums,n,t);
        int e=f2(nums,n,t);
        ans.push_back(s);
        ans.push_back(e);
        return ans;

        
    }
};