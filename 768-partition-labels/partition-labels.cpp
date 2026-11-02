class Solution {
public:
    vector<int> partitionLabels(string s) {

        int n=s.size();
        unordered_map<char,int> m;
        vector<int> ans;
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }
        int i=0;
        while(i<n){
            int j=i;
            int end=m[s[i]];
            while(j<end){
                end=max(end,m[s[j]]);
                j++;
            }
            ans.push_back(j-i+1);
            i=j+1;
        }
        return ans;
        
    }
};