class NumArray {
public:
    vector<int> bit;
    vector<int> arr;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        bit.assign(n+1,0);
        arr=nums;
        for(int i=0;i<n;i++){
            update_bit(i+1,arr[i]);
        }
    }

    void update_bit(int id,int val){
        while(id<=n){
            bit[id]+=val;
            id+=(id&(-id));
        }
    }
    
    void update(int index, int val) {
        int id=index+1;
        int old_val=arr[index];
        update_bit(id,-old_val);
        update_bit(id,val);
        arr[index]=val;
    }

    int query(int id){
        int ans=0;
        while(id>0){
            ans+=bit[id];
            id-=(id&(-id));
        }
        return ans;
    }
    
    int sumRange(int left, int right) {
        int l=left+1,r=right+1;
        int ans=query(r)-query(l-1);
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */