class Solution {
public:
    string toLowerCase(string s) {

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            s[i]=tolower(ch);
        }
        return s;
        
    }
};