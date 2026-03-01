class Solution {
public:
    int longestBalanced(string s) {

        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> m;
            for(int j=i;j<n;j++){
                m[s[j]]++;
                int f=m[s[j]];
                bool possible=true;
                for(auto &x:m){
                    if(x.second!=f) possible=false;
                }
                if(possible){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
        
    }
};