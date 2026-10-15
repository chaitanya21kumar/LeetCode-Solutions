class Solution {
public:
    char f(vector<char> &v,char op){
        if(op=='!'){
            if(v[0]=='t') return 'f';
            return 't';
        }
        if(op=='&'){
            for(int i=0;i<v.size();i++){
                if(v[i]=='f') return 'f';
            }
            return 't';
        }
        if(op=='|'){
            for(int i=0;i<v.size();i++){
                if(v[i]=='t') return 't';
            }
            return 'f';
        }
        return 't';
    }
    bool parseBoolExpr(string e) {

        int n=e.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            char ch=e[i];
            if(ch==',') continue;
            if(ch==')'){
                vector<char> v;
                while(!st.empty() && st.top()!='('){
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                char res=f(v,op);
                st.push(res);
            }
            else st.push(ch);
        }
        if(st.top()=='t') return true;
        return false;
        
    }
};