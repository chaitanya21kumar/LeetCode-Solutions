class Solution {
public:
    string getSmallestString(int n, int k) {

        string s(n,'a');
        k-=n;
        int i=n-1;
        while(k>0){
            int x=min(k,25);
            s[i--]+=x;
            k-=x;
        }
        return s;
        
    }
};