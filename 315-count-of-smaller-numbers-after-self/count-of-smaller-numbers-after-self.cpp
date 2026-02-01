class Solution {
public:
    vector<int> ans;
    void merge(int l,int mid,int r,vector<pair<int,int>> &arr){
        int left=l;
        int right=mid+1;
        vector<pair<int,int>> temp;
        while(left<=mid && right<=r){
            if(arr[left].first>arr[right].first){
                ans[arr[left].second]+=r-right+1;
                temp.push_back(arr[left++]);
            }
            else{
                temp.push_back(arr[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(arr[left++]);
        }
        while(right<=r){
            temp.push_back(arr[right++]);
        }
        for(int i=l;i<=r;i++){
            arr[i]=temp[i-l];
        }
    }
    void mergesort(int l,int r,vector<pair<int,int>> &v){
        if(l>=r) return;
        int mid=(l+(r-l)/2);
        mergesort(l,mid,v);
        mergesort(mid+1,r,v);
        merge(l,mid,r,v);
    }
    vector<int> countSmaller(vector<int>& nums) {

        int n=nums.size();
        ans.assign(n,0);
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={nums[i],i};
        }
        mergesort(0,n-1,v);
        return ans;
        
    }
};