class Solution {
public:
    string longestNiceSubstring(string s) {

        int n=s.size();
        if(n<2) return "";
        unordered_set<char> st;
        for(auto &x:s) st.insert(x);
        for(int i=0;i<n;i++){
            if(st.count(tolower(s[i])) && st.count(toupper(s[i]))) continue;
            string left=longestNiceSubstring(s.substr(0,i));
            string right=longestNiceSubstring(s.substr(i+1));
            if(left.length()>=right.length()) return left;
            return right;
        }
        return s;
        
    }
};