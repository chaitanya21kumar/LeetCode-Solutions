class Solution {
public:
    struct trieNode{

        bool we;
        string w;
        trieNode* c[26];

        trieNode* getNode(){
            trieNode* temp=getNode();
            temp->we=false;
            temp->w="";
            for(int i=0;i<26;i++){
                temp->c[i]=NULL;
            }
            return temp;
        }

    };
    trieNode* root=new trieNode();
    void insert(string word){
        trieNode* crawler=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(crawler->c[idx]==NULL){
                trieNode* temp=new trieNode();
                crawler->c[idx]=temp;
            }
            crawler=crawler->c[idx];
        }
        crawler->we=true;
        crawler->w=word;
    }
    vector<string> ans;
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i,int j,int m,int n,vector<vector<char>>& board,trieNode* crawler){
        if(board[i][j]=='$') return;
        char ch=board[i][j];
        int idx=ch-'a';
        if(crawler->c[idx]==NULL) return;
        crawler=crawler->c[idx];
        if(crawler->we==true){
            ans.push_back(crawler->w);
            crawler->we=false;
        }
        board[i][j]='$';
        for(auto &x:dirs){
            int ii=i+x[0];
            int jj=j+x[1];
            if(ii>=0 && ii<m && jj>=0 && jj<n){
                dfs(ii,jj,m,n,board,crawler);
            }
        }
        board[i][j]=ch;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        int m=board.size();
        int n=board[0].size();
        for(auto &x:words){
            insert(x);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                trieNode* crawler=root;
                int idx=board[i][j]-'a';
                if(crawler->c[idx]!=NULL){
                    dfs(i,j,m,n,board,crawler);
                }
            }
        }
        return ans;

    }
};