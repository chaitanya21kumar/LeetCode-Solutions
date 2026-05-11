class Solution {
public:
    int minFlips(string s) {

        int n=s.size();
        int c1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') c1++;
        }

        // all zeros 
        int cost1=c1;

        // all ones
        int cost2=n-c1;

        // exactly 1 one
        int cost3=(c1==0)?1:c1-1;

        // 1...00...1
        int cost4=INT_MAX;
        int x=0;
        if(n>=2){
            if(s[0]=='0') x++;
            if(s[n-1]=='0') x++;
            if(s[0]=='1') c1--;
            if(s[n-1]=='1') c1--;
        }
        cost4=x+c1;

        return min({cost1,cost2,cost3,cost4});

    }
};