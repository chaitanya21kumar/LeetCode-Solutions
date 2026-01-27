class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        int n=seats.size();
        int last1=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                if(last1==-1){
                    ans=max(ans,i);
                }
                else{
                    int x=(int)ceil((double)(i-last1-1)/2);
                    ans=max(ans,x);
                }
                last1=i;
            }
        }
        ans=max(ans,(n-1-last1));
        return ans;
        
    }
};