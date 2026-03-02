class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {

        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(nums[i]);
                continue;
            }
            while(!st.empty() && gcd(st.top(),nums[i])>1 ){
                int x=st.top();
                st.pop();
                nums[i]=lcm(nums[i],x);
            }
            st.push(nums[i]);
        }
        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
         
    }
};