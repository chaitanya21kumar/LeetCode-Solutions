class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n=strs.size();
        unordered_map<string,vector<string>> m;

        for(auto org:strs){
            string x=org;
            sort(x.begin(),x.end());
            m[x].push_back(org);
        }
        vector<vector<string>> ans;

        for(auto x:m){
            ans.push_back(x.second);
        }

        return ans;
        
    }
};