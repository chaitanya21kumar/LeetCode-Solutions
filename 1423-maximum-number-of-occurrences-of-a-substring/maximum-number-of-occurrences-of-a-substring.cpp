class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n=s.size();
        unordered_map<string,int> m;
        int ans=0;
        for(int i=0;i+minSize<=n;i++){
            string str=s.substr(i,minSize);
            unordered_set<char> st;
            for(auto &x:str) st.insert(x);
            if(st.size()<=maxLetters) m[str]++;
            ans=max(ans,m[str]);
        }
        return ans;
    }
};