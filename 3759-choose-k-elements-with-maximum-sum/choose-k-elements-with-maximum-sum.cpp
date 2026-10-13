class Solution {
public:
    typedef long long int ll;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {

        ll n=nums1.size();
        vector<vector<ll>> v(n);
        for(ll i=0;i<n;i++){
            v[i]={nums1[i],i,nums2[i]};
        }
        sort(v.begin(),v.end());
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll s=0;
        vector<ll> ans(n);
        for(int i=0;i<n;i++){
            if(i>0 && v[i][0]==v[i-1][0]){
                ans[v[i][1]]=ans[v[i-1][1]];
            }
            else ans[v[i][1]]=s;
            s+=(ll)v[i][2];
            pq.push(v[i][2]);
            if(pq.size()>k){
                s-=pq.top();
                pq.pop();
            }
        }
        return ans;
        
    }
};