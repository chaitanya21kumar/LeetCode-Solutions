class Solution {
public:
    typedef long long int ll;
    long long minMoves(vector<int>& balance) {

        ll n=balance.size();
        ll nidx=-1;
        ll ts=0;
        for(int i=0;i<n;i++){
            if(balance[i]<0) nidx=i;
            ts+=balance[i];
        }
        if(ts<0) return -1;
        if(nidx==-1) return 0;
        ll distance=1;
        ll moves=0;
        while(balance[nidx]<0){

            ll l=(nidx-distance+n)%n;
            ll r=(nidx+distance)%n;

            ll total=balance[l]+balance[r];
            if(l==r) total-=balance[l];
            ll need=min(total,-1LL*balance[nidx]);
            balance[nidx]+=need;
            moves+=(distance*need);
            distance++;
        }
        return moves;
        
    }
};