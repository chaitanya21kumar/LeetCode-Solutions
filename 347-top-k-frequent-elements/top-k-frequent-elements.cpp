class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) m[nums[i]]++;

        vector<vector<int>> v(n+1);

        for(auto x:m){
            int f=x.second,val=x.first;
            v[f].push_back(val);
        }

        vector<int> ans;

        for(int i=n;i>=0;i--){
            for(auto x:v[i]){
                if(ans.size()==k) break;
                ans.push_back(x);
            }
        }
        return ans;
        
    }
};