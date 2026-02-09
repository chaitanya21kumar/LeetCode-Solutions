class Solution {
public:
    typedef pair<int,char> p;
    string longestDiverseString(int a, int b, int c) {

        priority_queue<p> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string s="";
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            auto ch=x.second;
            auto f=x.first;
            int n=s.size();
            if(n>=2 && s[n-1]==ch && s[n-2]==ch){
                if(pq.empty()) break;
                auto y=pq.top();
                auto ch2=y.second;
                auto f2=y.first;
                s+=ch2;
                pq.pop();
                f2--;
                if(f2>0) pq.push({f2,ch2});
            }
            else{
                s+=ch;
                f--;
            }
            if(f>0) pq.push({f,ch});
        }
        return s;


        
    }
};