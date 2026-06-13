class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> sortedScore(n);
        
        for (int i = 0; i < n; ++i) {
            sortedScore[i] = {score[i], i};
        }
        
        sort(sortedScore.rbegin(), sortedScore.rend());
        
        vector<string> ans(n);
        
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ans[sortedScore[i].second] = "Gold Medal";
            } else if (i == 1) {
                ans[sortedScore[i].second] = "Silver Medal";
            } else if (i == 2) {
                ans[sortedScore[i].second] = "Bronze Medal";
            } else {
                ans[sortedScore[i].second] = to_string(i + 1);
            }
        }
        
        return ans;
    }
};