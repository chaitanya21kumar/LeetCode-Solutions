class Solution {
public:
    unordered_map<string,int> m;
    int f(int i,string &s,int n,vector<string>& arr){
        if(i>=n) return 0;
        if(m.find(s)!=m.end()) return m[s];
        unordered_set<char> st;
        bool p=1;
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])!=st.end()){
                p=0;
                break;
            }
            else st.insert(s[i]);
        }
        
        for(int j=0;j<arr[i].size();j++){
            if(st.find(arr[i][j])!=st.end()){
                p=0;
                break;
            }
            else st.insert(arr[i][j]);
        }
        int pick=INT_MIN;
        if(p==1){
            string str=s+arr[i];
            pick=arr[i].size()+f(i+1,str,n,arr);
        }
        int notpick=f(i+1,s,n,arr);
        return m[s]=max(pick,notpick);

    }
    int maxLength(vector<string>& arr) {

        int n=arr.size();
        string s="";
        return f(0,s,n,arr);
        
    }
};