class Solution {
public:
    bool f(string &s1,string &s2){
        int c=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) c++;
            if(c>1) return false;
        }
        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {

        int n=words.size();
        vector<int> parent(n,-1);
        vector<int> dp(n,1);
        int lsi=0;
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(groups[i]!=groups[j] && words[i].length()==words[j].length() && f(words[i],words[j])){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                        if(dp[i]>ans){
                            ans=dp[i];
                            lsi=i;
                        }

                    }
                }
            }
        }

        vector<string> result;
        while(lsi!=-1){
            result.push_back(words[lsi]);
            lsi=parent[lsi];
        }

        reverse(result.begin(),result.end());
        return result;
        
    }
};