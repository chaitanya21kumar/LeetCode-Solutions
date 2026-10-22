class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int n=nums.size();
        vector<int> v1,v2;
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(nums[i]%3==1){
                v1.push_back(nums[i]);
            }
            else if(nums[i]%3==2){
                v2.push_back(nums[i]);
            }
        }
        if(s%3==0) return s;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int ans=0;
        if(s%3==1){
            int w1=(v1.size()>=1?v1[0]:INT_MAX);
            int w2=(v2.size()>=2?v2[0]+v2[1]:INT_MAX);
            ans=max(ans,s-min(w1,w2));
        }
        else if(s%3==2){
            int w1=(v2.size()>=1?v2[0]:INT_MAX);
            int w2=(v1.size()>=2?v1[0]+v1[1]:INT_MAX);
            ans=max(ans,s-min(w1,w2));
        }
        return ans;
        
    }
};