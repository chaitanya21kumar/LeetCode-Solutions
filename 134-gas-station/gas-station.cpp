class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n=gas.size();
        int cg=0,cc=0;
        for(int i=0;i<n;i++){
            cg+=gas[i];
            cc+=cost[i];
        }
        if(cc>cg) return -1;
        int s=0;
        int sidx=0;
        for(int i=0;i<n;i++){
            s+=gas[i];
            s-=cost[i];
            if(s<0){
                s=0;
                sidx=i+1;
            }
        }
        return sidx;
        
    }
};