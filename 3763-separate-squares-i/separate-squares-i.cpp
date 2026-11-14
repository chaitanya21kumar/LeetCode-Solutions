class Solution {
public:
    typedef double d;
    bool fg(d &my,vector<vector<int>>& squares,d &t){
        d ba=0.0;
        for(auto &x:squares){
            d by=x[1];
            d l=x[2];
            d ty=by+l;
            if(my>ty){
                ba+=l*l;
            }
            else if(my>by){
                ba+=(l*(my-by));
            }
        }
        return ba>=(t/2.0);
    }
    double separateSquares(vector<vector<int>>& squares) {

        d lo=INT_MAX;
        d hi=INT_MIN;
        d t=0.0;
        for(auto &x:squares){
            d y=x[1];
            d l=x[2];
            t+=l*l;
            lo=min(lo,y);
            hi=max(hi,y+l);
        }
        d ans=hi;
        while(hi-lo>1e-5){
            d my=lo+(hi-lo)/2;
            ans=my;
            if(fg(my,squares,t)==true){
                hi=my;
            }
            else lo=my;
        }
        return ans;
        
    }
};