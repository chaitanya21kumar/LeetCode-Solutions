class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        string start="0000";
        if(start==target) return 0;
        unordered_set<string> s(deadends.begin(),deadends.end());
        if(s.find(start)!=s.end()) return -1;
        queue<string> q;
        q.push(start);
        s.insert(start);
        int level=1;
        while(!q.empty()){
            int x=q.size();
            for(int i=0;i<x;i++){
                string curr=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    char ch=curr[j];
                    char inc=(ch=='9')?'0':ch+1;
                    char dec=(ch=='0')?'9':ch-1;

                    curr[j]=inc;
                    if(curr==target) return level;
                    if(s.find(curr)==s.end()){
                        s.insert(curr);
                        q.push(curr);
                    }

                    curr[j]=dec;
                    if(curr==target) return level;
                    if(s.find(curr)==s.end()){
                        s.insert(curr);
                        q.push(curr);
                    }

                    curr[j]=ch;
                }
            }
            level++;
        }
        return -1;
        
    }
};