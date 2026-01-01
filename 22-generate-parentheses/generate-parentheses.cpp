class Solution {
public:
    vector<string> v;
    int valid(string &curr,int n){
        int c=0;
        for(int i=0;i<2*n;i++){
            if(curr[i]=='('){
                c--;
            }
            else{
                c++;
            }
            if(c>0) return 0;
        }
        if(c==0) return 1;
        return 0;
    }
    void f(string &curr,int n){
        if(curr.length()==2*n){
            if(valid(curr,n)){
                v.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        f(curr,n);
        curr.pop_back();
        curr.push_back(')');
        f(curr,n);
        curr.pop_back();

    }
    vector<string> generateParenthesis(int n) {

        string curr="";
        f(curr,n);
        return v;

        
        
        
        
    }
};