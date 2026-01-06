class Solution {
public:
    int maxArea(vector<int>& height) {

        typedef long long int ll;
        ll n=height.size();
        ll l=0,r=n-1;
        ll ans=INT_MIN;
        while(l<r){
            ll w=r-l, h=min(height[l],height[r]);
            ans=max(ans,h*w);
            if(height[l]>height[r]) r--;
            else l++;
        }
        
        return ans;
    }
};