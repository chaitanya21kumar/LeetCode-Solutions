class Solution {
public:
    int minOperations(int n) {

        vector<int> v;  
        int s=1;
        for(int i=1;i<=n;i++){
            v.push_back(s);
            s+=2;
        }  
        int avg=0;
        for(int i=0;i<v.size();i++){
            avg+=v[i];
        }
        avg/=n;
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]>avg) break;
            else{
                ans+=(avg-v[i]);
            }
        }
        return ans;

    }
};