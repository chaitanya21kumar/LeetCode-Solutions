class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        int n=nums.size();
        if(n==0) return {};
        vector<string> v;
        string s="";
        int sn=nums[0]; // starting num
        s=s+to_string(nums[0]);
        int ln=nums[0];
        for(int i=1;i<n;i++){
            int cn=nums[i];
            if(ln+1==cn){
                
            }
            else{
                if(sn==ln){
                    v.push_back(s);
                    s=to_string(nums[i]);
                }
                else{
                    s=s+"->"+to_string(ln);
                    v.push_back(s);
                    s=to_string(nums[i]);
                }
                sn=nums[i];
            }
            ln=nums[i];
        }
        if(s.size()>0){
            if(ln!=sn){
                s=s+"->"+to_string(ln);
            }
            v.push_back(s);
        }
        return v;
        
    }
};