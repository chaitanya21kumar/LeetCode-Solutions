class Solution {
public:
    bool f(int m,vector<vector<int>> &v,int n){
        for(int i=0;i<n;i++){
            if(m>=v[i][1]){
                m-=v[i][2];
            }
            else return false;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {

        int n=tasks.size();
        vector<vector<int>> v;
        int lo=0;
        int hi=0;
        for(int i=0;i<n;i++){
            hi+=tasks[i][1];
            int diff=tasks[i][1]-tasks[i][0];
            v.push_back({diff,tasks[i][1],tasks[i][0]});
        }
        sort(v.rbegin(),v.rend());
        int ans=INT_MAX;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(f(mid,v,n)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;

    }
};