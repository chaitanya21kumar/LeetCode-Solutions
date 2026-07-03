class Solution {
public:
    typedef long long int ll;
    int countValidSubarrays(vector<int>& nums, int x) {

        int n=nums.size();
        int c=0;

        for(int i=0;i<n;i++){
            ll s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                int ld=s%10;
                ll t=s;
                while(t>=10){
                    t/=10;
                }
                if(t==x && ld==x) c++;
            }
        }

        return c;

    }
};