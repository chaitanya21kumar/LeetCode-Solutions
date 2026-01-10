class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {

        typedef long long int ll;
        ll n=s.size();
        ll type0=0,type1=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                if(s[i]=='0') type0++;
                else type1++;
            }
        }

        ll ans=0;

        ll cost1=min(ll(swapCost),(ll)2*flipCost); // min cost to fix one type 0 and one type 1;
        ll pairs=min(type0,type1); 

        ans+=(pairs*cost1);

        ll remaining=abs(type0-type1);

        ll cost2=min((ll)crossCost+(ll)swapCost,(ll)2*flipCost); // min cost to fix 2 same type 

        ans+=(remaining/2)*cost2;

        if(remaining%2!=0) ans+=flipCost;

        return ans;





        
    }
};