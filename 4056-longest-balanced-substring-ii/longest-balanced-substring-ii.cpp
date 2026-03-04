class Solution {
public:
    int f(char ch1,char ch2,string &s){
        int c1=0,c2=0;
        unordered_map<int,int> m;
        int mxl=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==ch1) c1++;
            else if(s[i]==ch2) c2++;
            else{
                c1=0;
                c2=0;
                m.clear();
            }
            if(c1==c2) mxl=max(mxl,c1+c2);
            if(m.count(c1-c2)){
                mxl=max(mxl,i-m[c1-c2]);
            }
            else m[c1-c2]=i;
        }
        return mxl;
    }
    int longestBalanced(string s) {

        int n=s.size();
        int mxl=1;

        // case 1
        int c=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                c++;
            }
            else c=1;
            mxl=max(mxl,c);
        }

        // case 2

        int c1=f('a','b',s);
        int c2=f('b','c',s);
        int c3=f('a','c',s);
        mxl=max({mxl,c1,c2,c3});

        // case 3

        int cc1=0,cc2=0,cc3=0;
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            if(s[i]=='a') cc1++;
            else if(s[i]=='b') cc2++;
            else if(s[i]=='c') cc3++;
            if(cc1==cc2 && cc2==cc3){
                mxl=max(mxl,cc1+cc2+cc3);
            }
            int d1=cc1-cc2;
            int d2=cc1-cc3;
            string k=to_string(d1)+"_"+to_string(d2);
            if(m.count(k)){
                mxl=max(mxl,i-m[k]);
            }
            else m[k]=i;
        }


        return mxl;



        
    }
};