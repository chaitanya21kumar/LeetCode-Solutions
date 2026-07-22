class Solution {
public:
    string reverseWords(string s) {

        int n=s.size();
        stringstream ss(s);
        string word;
        string ans="";
        while(ss>>word){
            int l=0;
            int r=word.size()-1;
            while(l<r){
                swap(word[l],word[r]);
                l++;
                r--;
            }
            ans+=word+" ";
        }
        ans.pop_back();
        return ans;

    }
};