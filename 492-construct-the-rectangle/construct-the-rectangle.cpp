class Solution {
public:
    typedef long long int ll;
    vector<int> constructRectangle(int area) {

        ll l=-1,r=-1;
        ll diff=INT_MAX;
        for(int i=1;i<=area;i++){
            ll li=i;
            ll ri=area/li;
            if(li*ri==area && abs(li-ri)<=diff && li>=ri){
                l=li;
                r=ri;
                diff=abs(li-ri);
            }
        }
        vector<int> ans;
        ans.push_back(l);
        ans.push_back(r);
        return ans;
        
    }
};