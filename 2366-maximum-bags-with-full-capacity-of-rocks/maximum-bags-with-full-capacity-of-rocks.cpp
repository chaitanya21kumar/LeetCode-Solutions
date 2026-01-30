class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {

        int n=capacity.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=0;
        for(int i=0;i<n;i++){
            if(capacity[i]!=rocks[i]){
                pq.push(capacity[i]-rocks[i]);
            }
            else ans++;
        }
        while(additionalRocks>0 && !pq.empty()){
            auto x=pq.top();
            pq.pop();
            int diff=x;
            if(additionalRocks>=diff){
                additionalRocks-=diff;
                ans++;
            }  
        }
        return ans;
    }
};