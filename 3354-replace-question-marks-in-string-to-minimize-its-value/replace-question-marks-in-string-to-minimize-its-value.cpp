class Solution {
public:
    typedef pair<int,char> p;
    string minimizeStringValue(string s) {

        int n=s.size();
        vector<int> f(26,0);
        int cq=0; // count of q marks 
        for(int i=0;i<s.size();i++){
            if(s[i]!='?'){
                f[s[i]-'a']++;
            }
            else cq++;
        }
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i=0;i<f.size();i++){
            pq.push({f[i],('a'+i)});
        }
        string str="";
        while(cq>0){
            auto x=pq.top();
            auto ch=x.second;
            auto chc=x.first;
            str+=ch;
            pq.pop();
            pq.push({chc+1,ch});
            cq--;
        }
        int i=0;
        sort(str.begin(),str.end());
        for(int j=0;j<n;j++){
            if(s[j]=='?'){
                s[j]=str[i++];
            }
        }
        return s;   
    }
};