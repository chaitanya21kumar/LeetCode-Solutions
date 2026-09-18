class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        int m=image.size();
        int n=image[0].size();
        for(int i=0;i<m;i++){
            vector<int> v(n);
            for(int j=0;j<n;j++){
                v[j]=image[i][j];
            }
            for(int k=0;k<n;k++){
                image[i][k]=v[n-k-1];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                image[i][j]=1-image[i][j];
            }
        }
        return image;
        
    }
};