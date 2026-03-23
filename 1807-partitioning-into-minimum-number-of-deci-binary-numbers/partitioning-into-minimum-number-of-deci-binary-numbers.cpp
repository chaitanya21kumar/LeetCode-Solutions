class Solution {
public:
    int minPartitions(string n) {

        int mx=0;
        for(int i=0;i<n.size();i++){
            int x=n[i]-'0';
            mx=max(mx,x);
        }
        return mx;
        
    }
};