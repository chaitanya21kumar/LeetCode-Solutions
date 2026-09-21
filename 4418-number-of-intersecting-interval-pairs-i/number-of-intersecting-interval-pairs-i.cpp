class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        int ans=0;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int s1=intervals[i][0];
                int e1=intervals[i][1];
                int s2=intervals[j][0];
                int e2=intervals[j][1];
                if(e1>=s2) ans++;
            }
        }
        return ans;
        
    }
};