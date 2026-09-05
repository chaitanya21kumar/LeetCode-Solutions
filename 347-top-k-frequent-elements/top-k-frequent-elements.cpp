class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto &x:m){
            int ky=x.first;
            int f=x.second;
            pq.push({f,ky});
        }
        vector<int> ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;

    }
};