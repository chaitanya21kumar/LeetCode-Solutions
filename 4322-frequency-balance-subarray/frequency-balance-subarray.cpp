class Solution {
public:
    int getLength(vector<int>& nums) {

        int n=nums.size();
        unordered_map<int,int> f,fc;

        int ans=0;

        for(int i=0;i<n;i++){
            f.clear();
            fc.clear();
            for(int j=i;j<n;j++){

                int x=nums[j];
                int of=f[x];
                if(of>0){
                    fc[of]--;
                    if(fc[of]==0) fc.erase(of);
                }

                int nf=of+1;
                fc[nf]++;
                f[x]++;

                if(f.size()==1){
                    ans=max(ans,j-i+1);
                }
                else if(fc.size()==2){
                    auto it=fc.begin();
                    int f1=it->first;
                    it++;
                    int f2=it->first;
                    if(f1==2*f2 || f2==2*f1){
                        ans=max(ans,j-i+1);
                    }
                }
            }
            
        }
        return ans;
        
    }
};