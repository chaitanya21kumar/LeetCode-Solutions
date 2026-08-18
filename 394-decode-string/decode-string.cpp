class Solution {
public:
    string decodeString(string s) {

        int n=s.size();
        stack<int> cs;
        stack<string> ss;

        string curr="";
        int num=0;

        for(auto &x:s){
            if(isdigit(x)){
                num=num*10+(x-'0');
            }
            else if(x=='['){
                cs.push(num);
                ss.push(curr);
                num=0;
                curr="";
            }
            else if(x==']'){
                int c=cs.top();
                cs.pop();
                string s=ss.top();
                ss.pop();
                for(int i=0;i<c;i++){
                    s+=curr;
                }
                curr=s;
            }
            else{
                curr+=x;
            }
        }
        return curr;
        
    }
};