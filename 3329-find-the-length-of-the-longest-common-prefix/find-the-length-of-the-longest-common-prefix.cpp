struct trieNode{
    trieNode* children[10];
};

class Solution {
public:

    trieNode* getNode(){

        trieNode* temp=new trieNode();
        for(int i=0;i<10;i++){
            temp->children[i]=NULL;
        }
        return temp;

    }

    void insert(int num,trieNode* root){

        string s=to_string(num);
        trieNode* crawler=root;
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'0';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getNode();
            }
            crawler=crawler->children[idx];
        }

    }

    int search(int num,trieNode* root){

        int len=0;
        string s=to_string(num);
        trieNode* crawler=root;
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'0';
            if(crawler->children[idx]==NULL) break;
            else{
                len++;
                crawler=crawler->children[idx];
            }
        }
        return len;

    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        trieNode* root=new trieNode();

        for(int i=0;i<arr1.size();i++){
            insert(arr1[i],root);
        }

        int ans=0;
        for(int i=0;i<arr2.size();i++){
            ans=max(ans,search(arr2[i],root));
        }

        return ans;
        
    }
};