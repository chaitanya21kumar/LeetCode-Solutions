class Solution {
public:
    int n;
    vector<int> bit;
    void update(int id,int val){
        while(id<=n){
            bit[id]+=val;
            id+=(id&(-id));
        }
    }
    int query(int id){
        int ans=0;
        while(id>0){
            ans+=bit[id];
            id-=(id&(-id));
        }
        return ans;
    }
    int findKthEmptySlot(int k){
        int l=1,r=n;
        int idx=-1;
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(query(mid)>=k){
                idx=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return idx;
    }
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        n=nums.size();
        bit.assign(n+1,0);
        for(int i=0;i<n;i++){
            update(i+1,1);
        }
        vector<int> result(n);
        for(int i=n-1;i>=0;i--){
            int k=index[i]+1;
            int pos=findKthEmptySlot(k);
            result[pos-1]=nums[i];
            update(pos,-1);
        }
        return result;
        
    }
};