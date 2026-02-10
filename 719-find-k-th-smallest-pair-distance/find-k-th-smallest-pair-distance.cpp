class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        vector<int> v(mx-mn+1,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=abs(nums[i]-nums[j]);
                v[d]++;
            }
        }
        for(int i=0;i<v.size();i++){
            k-=v[i];
            if(k<=0) return i;
        }
        return 0;
        
    }
};