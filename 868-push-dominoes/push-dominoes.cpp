class Solution {
public:
    string pushDominoes(string d) {

        int n=d.size();
        vector<int> lcr(n),rcl(n);
        for(int i=0;i<n;i++){
            if(d[i]=='R'){
                lcr[i]=i;
            }
            else if(d[i]=='.'){
                lcr[i]=(i-1>=0?lcr[i-1]:-1);
            }
            else{
                lcr[i]=-1;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(d[i]=='L'){
                rcl[i]=i;
            }
            else if(d[i]=='.'){
                rcl[i]=(i+1<=n-1?rcl[i+1]:-1);
            }
            else rcl[i]=-1;
        }
        string ans="";
        for(int i=0;i<n;i++){
            int dlcr=abs(i-lcr[i]);
            int drcl=abs(i-rcl[i]);
            if(lcr[i]==-1 && rcl[i]==-1){
                ans+=".";
            }
            else if(lcr[i]==-1){
                ans+="L";
            }
            else if(rcl[i]==-1){
                ans+="R";
            }
            else if(drcl==dlcr){
                ans+=".";
            }
            else if(drcl<dlcr){
                ans+="L";
            }
            else ans+="R";
        }
        return ans;
        
    }
};