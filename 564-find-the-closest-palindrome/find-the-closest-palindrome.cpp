class Solution {
public:
    typedef long long int ll;
    ll f(ll n,int iseven){
        ll fh=n;
        if(iseven==1){
            fh/=10;
        }
        while(fh>0){
            int d=fh%10;
            fh/=10;
            n*=10;
            n+=d;
        }
        return n;
    }
    string nearestPalindromic(string n) {

        ll l=n.size();
        ll fh=stol(n.substr(0,(l%2==0)?l/2:(l/2)+1));
        vector<ll> ans;
        ans.push_back(f(fh,l%2));
        ans.push_back(f(fh+1,l%2));
        ans.push_back(f(fh-1,l%2));
        ans.push_back( ( (ll)pow(10,l-1) )-1 ) ;
        ans.push_back( (ll)pow(10,l) +1 );
        ll diff=INT_MAX;
        ll res=stol(n);
        ll org=stol(n);
        for(int i=0;i<ans.size();i++){
            if(org==ans[i]) continue;
            ll d=abs(org-ans[i]);
            if(d<diff){
                diff=d;
                res=ans[i];
            }
            else if(d==diff){
                res=min(res,ans[i]);
            }
        }
        return to_string(res);


        
    }
};