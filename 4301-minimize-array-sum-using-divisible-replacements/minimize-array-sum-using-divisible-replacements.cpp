class Solution {
public:
    typedef long long int ll;
    long long minArraySum(vector<int>& nums) {

        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> p(mx+1),d(mx+1);
        for(int i=0;i<n;i++){
            p[nums[i]]=1;
        }

        for(int i=1;i<=mx;i++){
            if(p[i]==1){
                for(int x=i;x<=mx;x+=i){
                    if(p[x]==1 && d[x]==0){
                        d[x]=i;
                    }
                }
            }
        }

        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=d[nums[i]];
        }
        return ans;
        
    }
};