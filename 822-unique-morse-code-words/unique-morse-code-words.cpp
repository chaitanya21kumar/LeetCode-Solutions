class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        int n=words.size();
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.",
                                "....","..",".---","-.-",".-..","--","-.",
                                "---",".--.","--.-",".-.","...","-","..-",
                                "...-",".--","-..-","-.--","--.."};

        unordered_set<string> s;
        for(auto &x:words){
            string str="";
            for(auto &y:x){
                str+=morse[y-'a'];
            }
            s.insert(str);
        }

        return s.size();

    }
};