class Solution {
public:
    int minMutation(string sg, string eg, vector<string>& bank) {

        unordered_set<string> s;
        for(auto &x:bank) s.insert(x);
        queue<pair<string,int>> q;
        q.push({sg,0});
        vector<char> v;
        v.push_back('A');
        v.push_back('C');
        v.push_back('G');
        v.push_back('T');
        unordered_set<string> vis;

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string word=q.front().first;
                int l=q.front().second;
                if(word==eg) return l;
                q.pop();
                for(auto &y:v){
                    for(int j=0;j<word.size();j++){
                        if(word[j]==y) continue;
                        char org=word[j];
                        word[j]=y;
                        if(vis.find(word)==s.end() && s.find(word)!=s.end()){
                            q.push({word,l+1});
                            vis.insert(word);
                        }
                        word[j]=org;
                    }
                }
            }
        }
        return -1;


        
    }
};