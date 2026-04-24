class Solution {
public:

    unordered_set<string> st;
    vector<int> memo;
    int f(int i,int n,string &s){
        if(i==n) return 0;
        if(memo[i]!=-1) return memo[i];
        int mn=1+f(i+1,n,s);
        string str="";
        for(int j=i;j<n;j++){
            str+=s[j];
            if(st.find(str)!=st.end()){
                int y=f(j+1,n,s);
                mn=min(mn,y);
            }
        }
        return memo[i]=mn;
    }
    int minExtraChar(string s, vector<string>& dictionary) {

        int n=s.size();
        // st.clear();
        memo.assign(n,-1);
        for(auto &x:dictionary){
            st.insert(x);
        }
        return f(0,n,s);

    }
};