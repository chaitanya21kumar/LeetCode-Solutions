class Solution {
public:
    bool isV(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            return true;
        }
        return false;
    }
    string toGoatLatin(string sentence) {

        stringstream ss(sentence);
        string word;
        string ans="";
        string as="a";
        while(ss>>word){
            if(!ans.empty()){
                ans+=" ";
            }
            if(isV(word[0])){
                ans+=word+"ma"+as;
            }
            else{
                ans+=word.substr(1)+word[0]+"ma"+as;
            }
            as+="a";
        }
        return ans;
        
    }
};