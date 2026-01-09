class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
        vector<int> v;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]) v.push_back(nums1[i++]);
            else v.push_back(nums2[j++]);
        }
        while(i<n1) v.push_back(nums1[i++]);
        while(j<n2) v.push_back(nums2[j++]);
        double ans=-1;
        int n=v.size();
        if(n%2==0){
            int idx1=n/2;
            int idx2=idx1-1;
            ans=(v[idx1]+v[idx2])/2.0;
        }
        else{
            int idx=n/2;
            ans=v[idx];
        }
        return ans;
        
    }
};