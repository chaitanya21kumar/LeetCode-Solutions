class Solution {
public:
    vector<string> v;
    void f(string &s,int n,int o,int c){
        if(s.size()==2*n){
            v.push_back(s);
            return;
        }

        if(o<n){
            s.push_back('(');
            f(s,n,o+1,c);
            s.pop_back();
        }
        if(c<o){
            s.push_back(')');
            f(s,n,o,c+1);
            s.pop_back();
        }


    }
    vector<string> generateParenthesis(int n) {

        string s="";
        int o=0,c=0;
        f(s,n,o,c);
        return v;
        
        
    }
};