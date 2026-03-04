class Solution {
public:
    unordered_map<string,vector<char>> m;
    unordered_set<string> fr; // failed rows
    bool f(string curr,string next,int i){
        if(curr.size()==1) return true;
        if(next.size()==curr.size()-1){
            if(fr.count(next)) return false;
            if(f(next,"",0)){
                return true;
            }
            else{
                fr.insert(next);
                return false;
            }
        }
        string bp=curr.substr(i,2);
        for(auto &x:m[bp]){
            if(f(curr,next+x,i+1)) return true;
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        for(auto &x:allowed){
            string str=x.substr(0,2);
            m[str].push_back(x[2]);
        }
        return f(bottom,"",0);
    }
};