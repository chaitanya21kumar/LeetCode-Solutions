class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        unordered_map<int,int> r,c,d,ad;
        set<pair<int,int>> s;
        for(auto &x:lamps){
            int rr=x[0],cc=x[1];
            if(s.find({rr,cc})==s.end()){
                s.insert({rr,cc});
                r[rr]++;c[cc]++;d[rr-cc]++;ad[rr+cc]++;
            }
        }
        vector<int> ans;
        for(auto &q:queries){
            int rr=q[0],cc=q[1];
            if(r[rr]>0 || c[cc]>0 || d[rr-cc]>0 || ad[rr+cc]>0) ans.push_back(1);
            else ans.push_back(0);
            for(int i=rr-1;i<=rr+1;i++){
                for(int j=cc-1;j<=cc+1;j++){
                    if(s.find({i,j})!=s.end()){
                        s.erase({i,j});
                        r[i]--;c[j]--;d[i-j]--;ad[i+j]--;
                    }
                }
            }
        }
        return ans;

        
    }
};