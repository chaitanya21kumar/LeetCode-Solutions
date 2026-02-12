class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n=arr.size();
        int od=0; // one deletion
        int nd=arr[0]; // no deletion
        int ans=arr[0];
        for(int i=1;i<n;i++){
            od=max(od+arr[i],nd);
            nd=max(arr[i],arr[i]+nd);
            ans=max({ans,od,nd});
        }
        return ans;
        
    }
};