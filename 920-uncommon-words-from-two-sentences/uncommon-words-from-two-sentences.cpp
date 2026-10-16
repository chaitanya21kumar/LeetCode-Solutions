class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        vector<string> ans;
        string s=s1+" "+s2;
        unordered_map<string,int> m;
        string w;
        stringstream ss(s);
        while(ss>>w){
            m[w]++;
        }
        for(auto &x:m){
            if(x.second==1){
                ans.push_back(x.first);
            }
        }
        return ans;
        
    }
};