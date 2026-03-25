class Solution {
public:
    bool canBeValid(string s, string locked) {

        int n=s.length();
        if(n%2!=0) return false;

        stack<int> o,oc;
        for(int i=0;i<n;i++){
            if(locked[i]=='0') oc.push(i);
            else if(locked[i]=='1'){
                if(s[i]=='('){
                    o.push(i);
                }
                else if(s[i]==')'){
                    if(!o.empty()) o.pop();
                    else{
                        if(!oc.empty()){
                            oc.pop();
                        }
                        else return false;
                    }
                }
            }
        }

        while(!o.empty() && !oc.empty() && oc.top()>o.top()){
            o.pop();
            oc.pop();
        }

        if(o.empty()) return true;
        return false;

    }
};