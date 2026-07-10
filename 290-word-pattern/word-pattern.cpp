class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> v;
        stringstream ss(s);
        string cw;

        while(ss>>cw){
            v.push_back(cw);
        }

        int n1=pattern.size();
        int n2=v.size();

        if(n1!=n2) return false;

        unordered_map<char,string> mcw; // map for char to word
        unordered_map<string,char> mwc; // map for word to char

        for(int i=0;i<n1;i++){
            char ch=pattern[i];
            string w=v[i];

            if(mcw.count(ch)>0){
                if(mcw[ch]!=w) return false;
            }

            if(mwc.count(w)>0){
                if(mwc[w]!=ch) return false;
            }

            mcw[ch]=w;
            mwc[w]=ch;
        }

        return true;

    }
};