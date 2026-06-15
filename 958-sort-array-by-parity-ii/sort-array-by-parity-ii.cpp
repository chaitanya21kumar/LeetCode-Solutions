class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        int n=nums.size();
        vector<int> o,e;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                e.push_back(nums[i]);
            }
            else o.push_back(nums[i]);
        }
        int oi=0,ei=0,i=0;
        while(oi<o.size() || ei<e.size() || i<n){

            if(i%2==0) nums[i++]=e[ei++];
            else nums[i++]=o[oi++];

        }
        return nums;
        
    }
};