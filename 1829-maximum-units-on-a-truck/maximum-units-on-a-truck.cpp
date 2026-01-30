class Solution {
public:
    static bool comp(const vector<int> &a,const vector<int> &b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        int n=boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),comp);

        int ans=0;
        for(int i=0;i<n;i++){
            int nou=boxTypes[i][1],nob=boxTypes[i][0];
            int mn=min(truckSize,nob);
            ans+=(mn*nou);
            truckSize-=mn;
        }
        return ans;
        
    }
};