class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,int n,int t,vector<int>& c,vector<int> &temp){
        if(t==0){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<n;j++){
            if(j>i && c[j]==c[j-1]) continue;
            if(c[j]>t) break;
            temp.push_back(c[j]);
            f(j+1,n,t-c[j],c,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {

        int n=c.size();

        vector<int> temp;
        sort(c.begin(),c.end());
        f(0,n,t,c,temp);

        return ans;


        
    }
};