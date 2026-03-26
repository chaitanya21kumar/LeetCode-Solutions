class Solution {
public:
    bool f(int idx,int n,string s){
        if(idx>=s.size()){
            if(n==0) return true;
            return false;
        }
        int cur=0;
        for(int i=idx;i<s.size();i++){
            cur=cur*10+(s[i]-'0');
            if(f(i+1,n-cur,s)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            string s=to_string(sq);
            if(f(0,i,s)) sum+=sq;
        }
        return sum;
    }
};