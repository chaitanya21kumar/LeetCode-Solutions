class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n=strs.size();
        unordered_map<string,vector<string>> m;
        for(int i=0;i<n;i++){
            string str=strs[i];
            sort(str.begin(),str.end());
            m[str].push_back(strs[i]);
        }
        vector<vector<string>> v;
        for(auto &x:m){
            v.push_back(x.second);
        }
        return v;
        
    }
};