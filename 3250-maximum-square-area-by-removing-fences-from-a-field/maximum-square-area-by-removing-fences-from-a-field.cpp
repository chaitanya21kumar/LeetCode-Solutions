class Solution {
public:
    typedef long long int ll;
    #define M 1000000007
    int maximizeSquareArea(int m, int n, vector<int>& hf, vector<int>& vf) {

        hf.push_back(1);
        hf.push_back(m);
        vf.push_back(1);
        vf.push_back(n);

        int ans=-1;

        unordered_set<int> hd;
        for(int i=0;i<hf.size();i++){
            for(int j=i+1;j<hf.size();j++){
                int x=abs(hf[i]-hf[j]);
                hd.insert(x);
            }
        }

        for(int i=0;i<vf.size();i++){
            for(int j=i+1;j<vf.size();j++){
                int x=abs(vf[i]-vf[j]);
                if(hd.find(x)!=hd.end()){
                    ans=max(ans,x);
                }
            }
        }
        if(ans!=-1){
            return ((ll(ans))*ans)%M;
        }
        return ans;

    }
};