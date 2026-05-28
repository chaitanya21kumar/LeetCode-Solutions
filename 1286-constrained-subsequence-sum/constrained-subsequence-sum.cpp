class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=nums[i];
        }
        for(int i=0;i<n;i++){
            while(!pq.empty() && i-pq.top().second>k) pq.pop();
            if(!pq.empty()){
                ans[i]=max(ans[i],ans[i]+pq.top().first);
            }
            pq.push({ans[i],i});
        }
        return *max_element(ans.begin(),ans.end());
        
    }
};