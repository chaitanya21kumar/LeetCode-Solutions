class Solution {
public:
    void f(int num,int n,int &r,int &c){
        num-=1;
        int row=num/n;
        int col=num%n;
        r=(n-row-1);
        if(row%2==0) c=col;
        else c=n-col-1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {

        int n=board.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        queue<int> q;
        q.push(1);
        int r,c;
        f(1,n,r,c);
        vis[r][c]=1;
        int ans=0;

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int cur=q.front();
                q.pop();
                if(cur==n*n) return ans;
                for(int k=1;k<=6;k++){
                    int next=cur+k;
                    if(next>n*n) break;
                    int dest;
                    f(next,n,r,c);
                    if(board[r][c]==-1){
                        dest=next;
                    }
                    else{
                        dest=board[r][c];
                        f(dest,n,r,c);
                    }
                    if(!vis[r][c]){
                        vis[r][c]=1;
                        q.push(dest);
                    }
                }
            }
            ans++;
        }
        return -1;
        
    }
};