class Solution {
public:
    static bool mycmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n=intervals.size();
        int c=0;
        sort(intervals.begin(),intervals.end(),mycmp);
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(ans.empty() || intervals[i][0]>=ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else c++;
        }
        return c;

       
        
    }
};