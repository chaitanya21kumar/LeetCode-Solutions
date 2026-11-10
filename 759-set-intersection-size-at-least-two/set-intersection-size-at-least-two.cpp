class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[1]==b[1]){
            return a[0]>b[0];
        }
        return a[1]<b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        int n=intervals.size();
        int f=-1,s=-1;
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=0;i<n;i++){
            int l=intervals[i][0];
            int r=intervals[i][1];
            if(l<=f){
                continue;
            }
            if(l>s){
                ans+=2;
                s=r;
                f=r-1;
            }
            else{
                ans+=1;
                f=s;
                s=r;
            }
        }
        return ans;

    }
};