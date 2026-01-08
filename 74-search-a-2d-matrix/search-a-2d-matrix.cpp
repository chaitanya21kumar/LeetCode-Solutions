class Solution {
public:
    bool bs(vector<int> &matrix,int target){
        int l=0,r=matrix.size()-1;
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(matrix[mid]==target) return true;
            else if(matrix[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m=matrix.size(),n=matrix[0].size();

        for(int i=0;i<m;i++){
            if(matrix[i][0]<=target && target<=matrix[i][n-1]){
                if(bs(matrix[i],target)) return true;
            }
        }
        return false;


        
    }
};