class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int> p;
        int n=nums.size();
        unordered_map<int,int> m;

        for(int i=0;i<n;i++) m[nums[i]]++;

        priority_queue<p,vector<p>,greater<p>> pq;

        for(auto x:m){
            int val=x.first,freq=x.second;
            pq.push({freq,val});
        }

        vector<int> ans;

        while(pq.size()>k) pq.pop();
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        
       
        
    }
};