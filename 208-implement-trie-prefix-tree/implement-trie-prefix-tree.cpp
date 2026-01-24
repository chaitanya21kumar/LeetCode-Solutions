class Trie {
public:
    struct trieNode{
        bool wordEnd;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* temp=new trieNode();
        temp->wordEnd=false;
        for(int i=0;i<26;i++){
            temp->children[i]=NULL;
        }
        return temp;
    }
    trieNode* root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        trieNode* crawler=root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(crawler->children[idx]==NULL) crawler->children[idx]=getNode();
            crawler=crawler->children[idx];
        }
        crawler->wordEnd=true;
    }
    
    bool search(string word) {
        trieNode* crawler=root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(crawler->children[idx]==NULL) return false;
            crawler=crawler->children[idx];
        }
        if(crawler->wordEnd==true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {

        trieNode* crawler=root;
        for(int i=0;i<prefix.size();i++){
            int idx=prefix[i]-'a';
            if(crawler->children[idx]==NULL) return false;
            crawler=crawler->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */