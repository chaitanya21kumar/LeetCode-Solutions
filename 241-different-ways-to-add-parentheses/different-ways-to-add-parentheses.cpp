class Solution {
public:
    vector<int> f(string s){
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                vector<int> l=f(s.substr(0,i));
                vector<int> r=f(s.substr(i+1));
                for(auto &x:l){
                    for(auto &y:r){
                        if(s[i]=='+'){
                            ans.push_back(x+y);
                        }
                        else if(s[i]=='-'){
                            ans.push_back(x-y);
                        }
                        else ans.push_back(x*y);
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(s));
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string s) {

        return f(s);
        
    }
};