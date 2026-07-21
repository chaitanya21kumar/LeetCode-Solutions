class Solution {
public:
    vector<int> selfDividingNumbers(int l, int r) {

        vector<int> ans;
        unordered_set<int> s;
        for(int i=l;i<=r;i++){
            int num=i;
            int n=num;
            bool poss=true;
            while(n>0){
                int d=n%10;
                if(d==0 || num%d!=0){
                    poss=false;
                    break;
                }
                n/=10;
            }
            if(poss) s.insert(num);
        }
        for(auto &x:s) ans.push_back(x);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};