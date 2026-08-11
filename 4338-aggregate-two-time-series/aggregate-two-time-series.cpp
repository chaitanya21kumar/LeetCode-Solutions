class Solution {
public:
    int f(vector<vector<int>>& series,int t){
        int lo=0;
        int hi=series.size()-1;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(series[mid][0]>=t){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        if(ans==-1) return 0;
        return series[ans][1];
    }
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        int n1=series1.size();
        int n2=series2.size();

        unordered_set<int> s;
        for(int i=0;i<n1;i++){
            s.insert(series1[i][0]);
        }
        for(int i=0;i<n2;i++){
            s.insert(series2[i][0]);
        }
        vector<int> v(s.begin(),s.end());
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        for(int i=0;i<v.size();i++){
            int v1=f(series1,v[i]);
            int v2=f(series2,v[i]);
            ans.push_back({v[i],v1+v2});
        }
        return ans;
        
    }
};