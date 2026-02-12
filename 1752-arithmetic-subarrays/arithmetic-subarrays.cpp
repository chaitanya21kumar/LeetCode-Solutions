class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        int n=nums.size();
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            int li=l[i],ri=r[i];
            vector<int> temp;
            for(int j=li;j<=ri;j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            int p=1;
            if(temp.size()<3){
                ans.push_back(true);
                continue;
            }
            for(int k=0;k<temp.size()-2;k++){
                if((temp[k+1]-temp[k])!=(temp[k+2]-temp[k+1])){
                    ans.push_back(false);
                    p=0;
                    break;
                }
            }
            if(p==1){
                ans.push_back(true);
            }
        }
        return ans;
        
    }
};