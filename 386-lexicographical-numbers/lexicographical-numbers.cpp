class Solution {
public:
    void f(int i,int n,vector<int> &ans){
        if(i>n) return;
        ans.push_back(i);
        for(int j=0;j<=9;j++){
            int nn=i*10+j;
            if(nn>n) return;
            f(nn,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {

        vector<int> ans;
        for(int i=1;i<=9;i++){
            f(i,n,ans);
        }
        return ans;
        
    }
};