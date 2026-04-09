class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        unordered_set<string> s(supplies.begin(),supplies.end());

        vector<string> ans;

        int n=recipes.size();
        unordered_map<string,vector<int>> adj;
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(s.find(ingredients[i][j])==s.end()){
                    adj[ingredients[i][j]].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto x=q.front();
            q.pop();
            string str=recipes[x];

            ans.push_back(str);

            for(auto &y:adj[str]){
                indegree[y]--;
                if(indegree[y]==0){
                    q.push(y);
                }
            }
        }

        return ans;
        



        
    }
};