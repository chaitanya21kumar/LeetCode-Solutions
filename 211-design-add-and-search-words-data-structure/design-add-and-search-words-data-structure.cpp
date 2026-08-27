class WordDictionary {
public:

    struct trieNode{
        trieNode* c[26];
        bool we;
    };

    trieNode* getNode(){
        trieNode* node=new trieNode();
        node->we=false;
        for(int i=0;i<26;i++){
            node->c[i]=NULL;
        }
        return node;
    }

    trieNode* root;
    

    WordDictionary() {
        root=getNode();
    }
    
    void addWord(string word) {

        trieNode* crawler=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(crawler->c[idx]==NULL){
                crawler->c[idx]=getNode();
            }
            crawler=crawler->c[idx];
        }
        crawler->we=true;
        
    }

    bool f(trieNode* root,string word){
        trieNode* crawler=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            char ch=word[i];
            if(ch=='.'){
                for(int j=0;j<26;j++){
                    if(crawler->c[j]!=NULL){
                        if(f(crawler->c[j],word.substr(i+1))) return true;
                    }
                }
                return false;
            }
            else if(crawler->c[idx]==NULL) return false;
            crawler=crawler->c[idx];
        }
        if(crawler!=NULL && crawler->we==true) return true;
        return false;
    }
    
    bool search(string word) {

        return f(root,word);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */