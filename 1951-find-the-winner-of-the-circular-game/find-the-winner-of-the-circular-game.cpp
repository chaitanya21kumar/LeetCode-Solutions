class Solution {
public:
    int findTheWinner(int n, int k) {

        int sz=n;
        int i=0;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        while(sz!=1){
            int temp=k-1;
            while(temp>0){
                if(v[i]!=-1){
                    i++;
                    temp--;
                }
                else{
                    i++;
                }
                i%=n;
            }
            while(v[i]==-1){
                i++;
                i%=n;
            }
            sz--;
            v[i]=-1;
            i++;
            i%=n;
        }
        for(int i=0;i<n;i++){
            if(v[i]!=-1) return v[i];
        }
        return -1;
    }
};