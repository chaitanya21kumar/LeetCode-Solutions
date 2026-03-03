class Solution {
public:
    string f(string s){
        int start=0,sum=0;
        vector<string> v;
        for(int i=0;i<s.size();i++){
            sum+=(s[i]=='1'?+1:-1);
            if(sum==0){
                string str=f(s.substr(start+1,i-start-1));
                v.push_back("1"+str+"0");
                start=i+1;
            }
        }
        sort(v.begin(),v.end(),greater<string>());
        string ans="";
        for(auto &x:v){
            ans+=x;
        }
        return ans;
    }
    string makeLargestSpecial(string s) {

        return f(s);
        
    }
};