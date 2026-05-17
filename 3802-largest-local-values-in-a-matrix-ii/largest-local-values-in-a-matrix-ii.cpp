class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<vector<int>>> v(n,vector<vector<int>> (m,vector<int> (m,INT_MIN)));

        for(int r=0;r<n;r++){
            for(int sc=0;sc<m;sc++){
                int mx=matrix[r][sc];
                for(int ec=sc;ec<m;ec++){
                    mx=max(mx,matrix[r][ec]);
                    v[r][sc][ec]=mx;
                }
            }
        }

        int ans=0;

        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                bool poss=true;
                if(matrix[r][c]==0) continue;
                int x=matrix[r][c];

                int sr=max(0,r-x);
                int er=min(n-1,r+x);
                
                for(int ri=sr;ri<=er;ri++){
                    int sc=max(0,c-x);
                    int ec=min(m-1,c+x);
                    if(ri==r-x || ri==r+x){
                        if(c-x>=0) sc++;
                        if(c+x<m) ec--;
                    }
                    if(sc<=ec && v[ri][sc][ec]>x){
                        poss=false;
                        break;
                    }
                }
                if(poss) ans++;
            }
        }

        return ans;
        
    }
};