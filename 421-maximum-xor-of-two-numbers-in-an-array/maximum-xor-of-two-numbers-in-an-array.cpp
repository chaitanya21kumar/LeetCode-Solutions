class Solution {
public:
    struct trieNode{
        trieNode* left;
        trieNode* right;
    };
    void insert(trieNode* root,int num){
        trieNode* crawler=root;
        for(int i=31;i>=0;i--){
            int ib=(num>>i)&1; // ith bit
            if(ib==0){
                if(crawler->left==NULL) crawler->left=new trieNode();
                crawler=crawler->left;
            }
            else{
                if(crawler->right==NULL) crawler->right=new trieNode();
                crawler=crawler->right;
            }
        }
    }
    int f(trieNode* root,int num){
        int mx=0;
        trieNode* crawler=root;
        for(int i=31;i>=0;i--){
            int ib=(num>>i)&1;
            if(ib==0){
                if(crawler->right!=NULL){
                    mx+=pow(2,i);
                    crawler=crawler->right;
                }
                else{
                    crawler=crawler->left;
                }
            }
            else{
                if(crawler->left!=NULL){
                    mx+=pow(2,i);
                    crawler=crawler->left;
                }
                else{
                    crawler=crawler->right;
                }
            }
        }
        return mx;
    }
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root=new trieNode();
        for(int i=0;i<nums.size();i++) insert(root,nums[i]);
        int mx=0;
        for(int i=0;i<nums.size();i++) mx=max(mx,f(root,nums[i]));
        return mx;
    }
};