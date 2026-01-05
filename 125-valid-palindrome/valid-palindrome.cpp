class Solution {
public:
    int ispal(string &str){
        int n=str.size();
        int i=0,j=n-1;
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++;j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        int n=s.size();
        set<char> st;
        for(char ch='a';ch<='z';ch++) st.insert(ch);
        for(char i='0';i<='9';i++) st.insert(i);

        string ans="";

        for(int i=0;i<n;i++){
            char ch=tolower(s[i]);
            if(st.find(ch)!=st.end()){
                ans+=ch;
            }
        }
        if(ispal(ans)) return true;
        return false;
        
        
    }
};