class Solution {
public:
    typedef long long int ll;
    ll cgi=0; // count of global inverions
    void merge(vector<int>& nums,int l,int m,int r){

        vector<int> temp(r-l+1);
        int k=0;
        int left=l,right=m+1;
        while(left<=m && right<=r){
            if(nums[left]<=nums[right]) temp[k++]=nums[left++];
            else{
                temp[k++]=nums[right++];
                cgi+=(m-left+1);
            }
        }
        while(left<=m) temp[k++]=nums[left++];
        while(right<=r) temp[k++]=nums[right++];
        for(int i=l;i<=r;i++) nums[i]=temp[i-l];

    }
    void mergesort(vector<int>& nums,int l,int r){

        if(l>=r) return;
        int m=(l+r)/2;
        mergesort(nums,l,m);
        mergesort(nums,m+1,r);
        merge(nums,l,m,r);
        
    }
    bool isIdealPermutation(vector<int>& nums) {

        ll cli=0; // count of local inversions

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) cli++;
        }

        mergesort(nums,0,nums.size()-1);
        return cgi==cli;
        
    }
};