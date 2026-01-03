class Solution {
public:
    vector<string> ans;
    void f(int idx,int n,string &digits,unordered_map<char,string> &m,string &temp){
        if(idx>=n){
            ans.push_back(temp);
            return;
        }
        char c=digits[idx];
        string str=m[c];
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            f(idx+1,n,digits,m,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        int n=digits.size();
        unordered_map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        string temp="";
        f(0,n,digits,m,temp);
        return ans;

        

        
    }
};