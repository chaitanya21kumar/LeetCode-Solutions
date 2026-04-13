class Solution {
public:
    bool f(vector<int>& tasks, vector<int>& workers,int m,int p,int s){
        multiset<int> ms(workers.begin(),workers.begin()+m);

        for(int i=m-1;i>=0;i--){
            auto it=ms.end();
            --it;
            int val=(*it);
            if(val>=tasks[i]){
                ms.erase(it);
            }
            else if(p>0){
                auto it2=ms.lower_bound(tasks[i]-s);
                if(it2==ms.end()) return false;
                ms.erase(it2);
                p--;
            }
            else return false;
        }

        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {

        int n=tasks.size();
        int m=workers.size();

        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater<int>());

        int lo=0;
        int hi=min(n,m);
        int ans=0;

        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);

            if(f(tasks,workers,mid,pills,strength)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }

        return ans;
        
    }
};