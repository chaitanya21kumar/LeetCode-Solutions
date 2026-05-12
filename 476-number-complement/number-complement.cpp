class Solution {
public:
    typedef long long int ll;
    int findComplement(int num) {

        string s="";

        while(num>0){
            if(num%2==0){
                s='0'+s;
            }
            else s='1'+s;
            num/=2;
        }

        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ans=ans+'0';
            }
            else ans=ans+'1';
        }
        ll m=1;
        ll n=0;
        for(int i=ans.size()-1;i>=0;i--){

            if(ans[i]=='1'){
                n=n+(m);
            }
            m*=2;


        }
        return n;
    }
};