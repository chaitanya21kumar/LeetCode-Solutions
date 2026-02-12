class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

        int n=s.size();
        vector<vector<int>> v(26,vector<int> (n,0));
        for(int i=0;i<26;i++){
            for(int j=0;j<n;j++){
                int cci=( (s[j]-'a')==i ? 1 : 0 );
                if(j==0){
                    v[i][j]=cci;
                }
                else v[i][j]=v[i][j-1]+cci;
            }
        }
        vector<bool> ans;
        for(auto &x:queries){
            int l=x[0],r=x[1],k=x[2];
            int oc=0;
            for(int i=0;i<26;i++){
                int c=0;
                if(l==0) c=v[i][r];
                else c=v[i][r]-v[i][l-1];
                if(c%2!=0) oc++;
            }
            if((oc/2)<=k) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
        
    }
};