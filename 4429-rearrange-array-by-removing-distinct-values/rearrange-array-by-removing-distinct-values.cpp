class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n=nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        vector<int> ans;
        while(ans.size()<nums.size()){
            for(auto &x:m){
                if(x.second>0){
                    ans.push_back(x.first);
                    x.second--;
                }
            }
        }
        return ans;
        
    }
};