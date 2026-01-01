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
            o++;
            f(s,n,o,c);
            o--;
            s.pop_back();
        }
        if(c<o){
            s.push_back(')');
            c++;
            f(s,n,o,c);
            c--;
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