class Solution {
public:
    int c=0;
    void merge(vector<int>& arr,int l,int m,int r){
        vector<int> temp;
        int left=l,right=m+1;
        while(left<=m && right<=r){
            if(arr[left]<=arr[right]) temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }
        while(left<=m) temp.push_back(arr[left++]);
        while(right<=r) temp.push_back(arr[right++]);
        for(int i=l;i<=r;i++) arr[i]=temp[i-l];
    }
    void countpairs(vector<int>& arr,int l,int mid,int r){
        int left=l,right=mid+1;
        while(left<=mid && right<=r){
            if(1LL*arr[left]>1LL*2*arr[right]){
                c+=(mid-left+1);
                right++;
            }
            else left++;
        }
    }
    void mergesort(vector<int>& nums,int l,int r){
        if(l>=r) return;
        int mid=(l+(r-l)/2);
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,r);
        countpairs(nums,l,mid,r);
        merge(nums,l,mid,r);
    }
    int reversePairs(vector<int>& nums) {

        mergesort(nums,0,nums.size()-1);
        return c;

    


        
    }
};