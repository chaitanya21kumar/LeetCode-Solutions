class Solution {
public:
    bool possible(int n,vector<int>& quantities,int mid){
        int c=0;
        for(int i=0;i<quantities.size();i++){
            c+=(int)(ceil((double)quantities[i]/(double)(mid)));
        }

        return c<=n;
        
    }
    int minimizedMaximum(int n, vector<int>& quantities) {

        int lo=1;
        int hi=*max_element(quantities.begin(),quantities.end());
        int ans=hi;

        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(possible(n,quantities,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
        
    }
};