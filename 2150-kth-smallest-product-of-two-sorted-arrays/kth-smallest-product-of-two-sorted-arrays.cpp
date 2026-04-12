class Solution {
public:
    typedef long long int ll;
    ll f(vector<int>& nums1,vector<int>& nums2,ll mp,ll k){

        ll pc=0; // product count 
        ll n1=nums1.size();
        ll n2=nums2.size();

        for(int i=0;i<n1;i++){
            if(nums1[i]<0){

                ll l=0;
                ll r=n2-1;
                ll ans=n2;

                while(l<=r){
                    ll mid=(l+(r-l)/2);
                    ll prod=1LL*nums1[i]*nums2[mid];
                    if(prod<=mp){
                        ans=mid;
                        r=mid-1;
                    }
                    else l=mid+1;
                }

                pc+=(n2-ans);
            }
            else{

                ll l=0;
                ll r=n2-1;
                ll ans=-1;

                while(l<=r){
                    ll mid=(l+(r-l)/2);
                    ll prod=1LL*nums1[i]*nums2[mid];
                    if(prod<=mp){
                        ans=mid;
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }

                pc+=(ans+1);
            }
            
        }
        return pc;

    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {

        ll l=-1*10000000000;
        ll r=10000000000;
        ll ans=INT_MAX;

        while(l<=r){
            ll mid=(l+(r-l)/2);

            if(f(nums1,nums2,mid,k)>=k){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        return ans;

    }
};