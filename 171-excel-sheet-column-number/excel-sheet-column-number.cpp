class Solution {
public:
    typedef long long int ll;
    int titleToNumber(string columnTitle) {

        char ch='A';
        unordered_map<char,int> m;
        for(int i=1;i<=26;i++){
            m[ch]=i;
            ch++;
        }
        int ans=0;
        int j=0;
        int x=26;
        for(int i=columnTitle.length()-1;i>=0;i--){
            int mul=pow(x,j);
            ll val=m[columnTitle[i]]*mul;
            ans+=val;
            j++;
        }
        return ans;
        
    }
};