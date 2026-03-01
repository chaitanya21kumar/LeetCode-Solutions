class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n=nums.size();
        stack<int> st;
        int ops=0;
        for(int i=0;i<n;i++){
            if(st.empty() && nums[i]!=0){
                ops++;
                st.push(nums[i]);
                continue;
            }
            while(!st.empty() && st.top()>nums[i]){
                st.pop();
            }
            if(nums[i]!=0){
                if(st.empty()) ops++;
                else if(nums[i]!=st.top()) ops++;
            }
            st.push(nums[i]);
        }
        return ops;
        
    }
};