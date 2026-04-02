class Solution {
public:
    string addStrings(string num1, string num2) {

        int i=num1.size()-1;
        int j=num2.size()-1;
        int c=0;
        string ans="";
        while(i>=0 || j>=0 || c>0){
            int d1=i>=0 ? num1[i]-'0':0;
            int d2=j>=0 ? num2[j]-'0':0;
            int n=d1+d2+c;
            int ld=n%10;
            c=n/10;
            ans=to_string(ld)+ans;
            i--;
            j--;
        }
        return ans;
        
    }
};