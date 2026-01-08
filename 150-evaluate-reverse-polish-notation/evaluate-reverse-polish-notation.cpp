class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        typedef long long int ll;
        int n=tokens.size();
        stack<string> st;

        for(auto x:tokens){
            if(x!="+" && x!="-" && x!="*" && x!="/") st.push(x);
            else{
                ll ans=0;
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                ll n1=stoi(s1);
                ll n2=stoi(s2);
                if(x=="+"){
                    ans+=(n1+n2);
                }
                else if(x=="-"){
                    ans+=(n2-n1);
                }
                else if(x=="*"){
                    ans+=(n1*n2);
                }
                else if(x=="/"){
                    ans+=(n2/n1);
                }
                st.push(to_string(ans));
            }
        }

        return stoi(st.top());
        
    }
};