class Solution {
public:
    int countVowelSubstrings(string word) {

        vector<string> v;
        int n=word.size();
        for(int i=0;i<n;i++){
            string s="";
            for(int j=i;j<n;j++){
                s+=word[j];
                v.push_back(s);
            }
        }
        int c=0;
        for(auto &x:v){
            int ca=0,ce=0,ci=0,co=0,cu=0;
            int cd=0;
            for(int i=0;i<x.size();i++){
                if(x[i]=='a') ca++;
                else if(x[i]=='e') ce++;
                else if(x[i]=='i') ci++;
                else if(x[i]=='o') co++;
                else if(x[i]=='u') cu++;
                else cd++;
            }
            if(ca && ce && ci && co && cu && !cd) c++;
        }
        return c;
    }
};