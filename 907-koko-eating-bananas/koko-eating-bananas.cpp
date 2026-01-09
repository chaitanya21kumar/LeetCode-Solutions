class Solution {
public:
    int possible(double mid,vector<int>& piles,int h){
        double x=0;
        for(int i=0;i<piles.size();i++){
            x+=ceil(piles[i]/mid);
        }
        if(x<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int n=piles.size();
        double l=1,r=1e9;
        double ans=-1;

        while(l<=r){
            double mid=ceil(l+(r-l)/2);
            if(possible(mid,piles,h)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};