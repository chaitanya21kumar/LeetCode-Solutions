class Solution {
public:
    typedef long long int ll;
    vector<int> lexSmallestNegatedPerm(int n, long long t) {

        ll s=((ll)n*(n+1))/2;
        ll N=(s-t)/2;
        if(abs(t)>s || (s-t)%2!=0) return {};

        vector<int> isn(n+1); // is negative
        for(int i=n;i>=1;i--){
            if(N>=i){
                isn[i]=1;
                N-=i;
            }
        }
        vector<int> ans;
        for(int i=n;i>=1;i--){
            if(isn[i]==1){
                ans.push_back(-1*i);
            }
        }
        for(int i=1;i<=n;i++){
            if(isn[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};