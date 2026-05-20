class Solution {
public:
    void f(int x,int n,int k,vector<int> &bf,vector<int> &tf,int mnd){
        if(k==1){
            if(n>=x){
                tf.push_back(n);
                int diff=tf[tf.size()-1]-tf[0];
                if(diff<mnd){
                    mnd=diff;
                    bf=tf;
                }
                tf.pop_back();
                return;
            }
        }
        for(int i=x;i<=n;i++){
            if(n%i==0){
                tf.push_back(i);
                f(i,n/i,k-1,bf,tf,mnd);
                tf.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {

        int mnd=INT_MAX;
        vector<int> bf,tf; // best factors, temp factors
        f(1,n,k,bf,tf,mnd);
        return bf;
        
    }
};