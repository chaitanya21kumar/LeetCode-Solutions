class Solution {
public:
    typedef long long int ll;
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {

        int n=tasks.size();
        vector<ll> p(n);
        p[0]=tasks[0];
        for(int i=1;i<n;i++){
            p[i]=p[i-1]+tasks[i];
        }
        vector<int> ans;
        ll done=0;
        for(int i=0;i<shifts.size();i++){
            if(done+shifts[i]>=p[n-1]){
                ans.push_back(0);
                done=0;
            }
            else{
                done+=shifts[i];
                int idx=upper_bound(p.begin(),p.end(),done)-p.begin();
                ans.push_back(n-idx);
            }
        }
        return ans;
        
    }
};