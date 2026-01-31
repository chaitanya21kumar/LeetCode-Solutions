class Solution {
public:
    string rankTeams(vector<string>& votes) {

        int n=votes.size();
        vector<vector<int>> count(26,vector<int> (26,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<votes[i].size();j++){
                count[votes[i][j]-'A'][j]++;
            }
        }
        string result=votes[0];
        sort(result.begin(),result.end(),[&](char a,char b){
            for(int i=0;i<votes[0].size();i++){
                if(count[a-'A'][i]>count[b-'A'][i]) return true;
                if(count[a-'A'][i]<count[b-'A'][i]) return false;
            }
            return a<b;
        });
        return result;
        
    }
};