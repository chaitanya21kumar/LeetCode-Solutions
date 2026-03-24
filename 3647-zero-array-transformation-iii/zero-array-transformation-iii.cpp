class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {

        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> u; // used
        priority_queue<int> a; // available
        sort(queries.begin(),queries.end());
        int qi=0; // queries idx
        int uc=0; // used count of queries

        int qs=queries.size();

        for(int i=0;i<n;i++){
            while(qi<qs && queries[qi][0]<=i){
                a.push(queries[qi][1]);
                qi++;
            }
            nums[i]-=u.size();
            while(nums[i]>0 && !a.empty() && a.top()>=i){
                u.push(a.top());
                a.pop();
                nums[i]--;
                uc++;
            }
            if(nums[i]>0) return -1;
            while(!u.empty() && u.top()==i) u.pop();
        }

        return qs-uc;
        
    }
};