class Solution {
public:
    int f(int n,int k){
        if(n==1) return 0;
        int idx=(f(n-1,k)+k)%n;
        return idx;
    }
    int findTheWinner(int n, int k) {

        return f(n,k)+1;
        
    }
};