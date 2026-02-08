class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        typedef long long int ll;
        set<pair<ll,ll>> s;
        vector<vector<ll>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        ll x=0,y=0,d=0,dir=0;
        for(auto &ob:obstacles){
            s.insert({ob[0],ob[1]});
        }
        for(auto &c:commands){
            if(c==-1) dir=(dir+1)%4;
            else if(c==-2) dir=(dir+3)%4;
            else{
                for(ll i=0;i<c;i++){
                    ll xx=x+dirs[dir][0];
                    ll yy=y+dirs[dir][1];
                    if(s.find({xx,yy})!=s.end()) break;
                    x=xx;
                    y=yy;
                    d=max(d,((ll)xx*xx)+((ll)yy*yy));
                }
            }
        }
        return d;
        
    }
};