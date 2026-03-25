class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        int n=nums.size();
        int l=0,r=0,ans=0;
        int cd=0,k=0;
        unordered_set<int> s;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
                cd++;
            }
        }
        while(r<n){
            if(m[nums[r]]==0){
                k++;
            }
            m[nums[r]]++;
            while(k==cd){
                ans+=(n-r);
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    k--;
                }
                l++;
            }
            r++;
        }
        return ans;
        
    }
};