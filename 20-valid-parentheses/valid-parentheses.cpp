class Solution {
public:
    bool isValid(string s) {

        int n=s.size();
        stack<char> st;
        for(auto x:s){
            char ch='#';
            if(!st.empty()){
                ch=st.top();
            }
            if(x=='(' || x=='{' || x=='['){
                st.push(x);
                continue;
            }
            else if(x==')'){
                if(ch!='(') return false; 
                
            }
            else if(x=='}'){
                if(ch!='{') return false;
            }
            else if(x==']'){
                if(ch!='[') return false;
            }
            st.pop();
        }

        if(st.empty()) return true;
        return false;
        
    }
};