class Solution {
public:
    vector<string> result;
    int m,n;
    struct trieNode{
        bool wordEnd;
        string word;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* temp=new trieNode();
        temp->wordEnd=false;
        temp->word="";
        for(int i=0;i<26;i++){
            temp->children[i]=NULL;
        }
        return temp;
    }
    void insert(trieNode* root,string &str){
        trieNode* crawler=root;
        for(auto &ch:str){
            if(crawler->children[ch-'a']==NULL) crawler->children[ch-'a']=getNode();
            crawler=crawler->children[ch-'a'];
        }
        crawler->word=str;
        crawler->wordEnd=true;
    }
    vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i,int j,vector<vector<char>>& board,trieNode* root){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='$' || root->children[board[i][j]-'a']==NULL) return;
        root=root->children[board[i][j]-'a'];
        if(root->wordEnd==true){
            result.push_back(root->word);
            root->wordEnd=false;
        }
        char ch=board[i][j];
        board[i][j]='$';
        for(auto &x:dir){
            int ii=i+x.first;
            int jj=j+x.second;
            dfs(ii,jj,board,root);
        }
        board[i][j]=ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        m=board.size();
        n=board[0].size();
        trieNode* root=getNode();
        for(auto &x:words) insert(root,x);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL) dfs(i,j,board,root);
            }
        }
        return result;
    }
};