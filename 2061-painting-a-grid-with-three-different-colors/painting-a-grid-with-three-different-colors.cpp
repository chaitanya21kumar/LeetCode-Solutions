class Solution {
public:
    typedef long long int ll;
    #define M 1000000007
    vector<string> v;
    void f(string s,char p,int m){
        if(s.size()==m){
            v.push_back(s);
            return;
        }

        for(auto &x:{'R','G','B'}){
            if(p!=x){
                s.push_back(x);
                f(s,x,m);
                s.pop_back();
            }
        }

    }
    int f1(int m,int n,int i,int cl,vector<vector<int>> &dp){

        if(cl==0) return 1;
        if(dp[i][cl]!=-1) return dp[i][cl];
        string ps=v[i];
        int ans=0;
        for(int j=0;j<v.size();j++){
            string cs=v[j];
            if(cs==ps) continue;
            bool poss=true;
            for(int k=0;k<ps.size();k++){
                if(ps[k]==cs[k]){
                    poss=false;
                    break;
                }
            }
            if(poss){
                ans=(ans+f1(m,n,j,cl-1,dp))%M;
            }
        }

        return dp[i][cl]=ans;

    }
    int colorTheGrid(int m, int n) {


        f("",'#',m);
        ll ans=0;
        vector<vector<int>> dp(130,vector<int> (n+10,-1));
        for(int i=0;i<v.size();i++){
            ans=(ans+f1(m,n,i,n-1,dp))%M;
        }
        return ans;
        
    }
};