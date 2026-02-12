class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int n=deck.size();
        vector<int> ans(n);
        sort(deck.begin(),deck.end());
        queue<int> q;
        for(int i=0;i<n;i++) q.push(i);
        int p=1;
        int i=0;
        while(!q.empty()){
            auto idx=q.front();
            q.pop();
            if(p==1){
                ans[idx]=deck[i++];
                p=0;
            }
            else{
                q.push(idx);
                p=1;
            }
        }
        return ans;
        
    }
};