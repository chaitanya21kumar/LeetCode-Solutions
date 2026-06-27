class Solution {
public:
    bool f(int mid,vector<int>& dist,double hour){
        int n=dist.size();
        double ans=0;
        for(int i=0;i<n;i++){
            int x=ceil(dist[i]/(double)(mid));
            if(i==n-1){
                ans+=(dist[i]/(double)(mid));
            }
            else ans+=x;
            if(ans>hour) return false;
        }
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {

        int n=dist.size();
        int lo=1;
        int hi=1e9;
        int ans=-1;

        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(f(mid,dist,hour)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;

    }
};