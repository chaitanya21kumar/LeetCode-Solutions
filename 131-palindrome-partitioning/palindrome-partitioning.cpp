class Solution {
public:
    vector<vector<string>> ans;
    int ispal(int i,int j,string &s){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    void f(int i,int n,string &s,vector<string> &temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<n;j++){
            if(ispal(i,j,s)){
                temp.push_back(s.substr(i,j-i+1));
                f(j+1,n,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        int n=s.size();
        f(0,n,s,temp);
        return ans;

        
    }
};