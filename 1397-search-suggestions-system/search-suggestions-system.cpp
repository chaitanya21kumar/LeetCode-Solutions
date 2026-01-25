class Solution {
public:
    struct trieNode{
        vector<string> suggestions;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* temp=new trieNode();
        for(int i=0;i<26;i++){
            temp->children[i]=NULL;
        }
        return temp;
    }
    void insert(trieNode* root,string &word){
        trieNode* crawl=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(crawl->children[idx]==NULL) crawl->children[idx]=getNode();
            crawl=crawl->children[idx];
            if(crawl->suggestions.size()<3) crawl->suggestions.push_back(word);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        trieNode* root=getNode();
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        for(auto &x:products){
            insert(root,x);
        }
        trieNode* crawl=root;
        for(int i=0;i<searchWord.size();i++){
            int idx=searchWord[i]-'a';
            if(crawl!=NULL && crawl->children[idx]!=NULL){
                crawl=crawl->children[idx];
                ans.push_back(crawl->suggestions);
            }
            else{
                crawl=NULL;
                ans.push_back({});
            }
        }
        return ans;
    }
};