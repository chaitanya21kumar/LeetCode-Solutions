class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {

        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> s(n);
        for(int i=0;i<n;i++){
            s[i]=intervals[i][0];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int e=intervals[i][1];
            auto it=upper_bound(s.begin()+i+1,s.end(),e);
            int d=it-(s.begin()+i+1);
            ans+=d;
        }
        return ans;
        
    }
};