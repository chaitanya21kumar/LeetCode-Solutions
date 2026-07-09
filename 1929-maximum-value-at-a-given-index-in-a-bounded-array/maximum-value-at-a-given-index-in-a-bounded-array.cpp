class Solution {
public:
    typedef long long int ll;
    ll f(int count,int peak){
        ll top=peak-1;

        if(count>=top){
            ll eo=count-top; // extra ones
            ll sos=(top*(top+1))/2;
            return eo+sos;
        }
        else{
            ll it=top-count; // invisible top
            ll sos=(top*(top+1))/2;
            ll soits=(it*(it+1))/2; // sum of it seq
            return sos-soits;
        }

    }
    int maxValue(int n, int index, int maxSum) {

        ll lo=1;
        ll hi=maxSum;
        ll ans=1;

        while(lo<=hi){
            ll mid=(lo+(hi-lo)/2);
            ll ls=f(index,mid);
            ll rs=f(n-index-1,mid);
            ll ts=ls+mid+rs;

            if(ts<=maxSum){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }

        return (int)ans;
        
    }
};