class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {

        vector<int> e,o;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) e.push_back(nums[i]);
            else o.push_back(nums[i]);
        }
        sort(e.begin(),e.end());
        sort(o.rbegin(),o.rend());
        int i=0,j=0,k=0;
        while(i<e.size() && j<o.size()){
            if(k%2==0){
                nums[k]=e[i++];
            }
            else{
                nums[k]=o[j++];
            }
            k++;
        }
        if(i<e.size()){
            nums[k]=e[i++];
        }
        else if(j<o.size()){
            nums[k]=o[j++];
        }
        return nums;
        
    }
};