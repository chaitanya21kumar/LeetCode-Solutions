class Solution {
public:
    int findTheWinner(int n, int k) {

        queue<int> q;
        for(int i=1;i<=n;i++) q.push(i);
        while(q.size()>1){
            int el=k-1;
            while(el>0){
                int x=q.front();
                q.pop();
                q.push(x);
                el--;
            }
            q.pop();
        }
        return q.front();
        
    }
};