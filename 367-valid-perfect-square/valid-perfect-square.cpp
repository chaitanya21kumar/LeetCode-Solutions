class Solution {
public:
    bool isPerfectSquare(int num) {

        int n=num;
        int x=sqrt(n);
        return x*x==n;
        
    }
};