class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int n=deck.size();
        vector<int> v(n,-1);
        int i=1;
        int j=0;
        sort(deck.begin(),deck.end());
        int gap=0;
        v[0]=deck[0];
        while(i<n){
            while(gap!=1){
                if(v[j]==-1){
                    gap++;
                }
                j++;
                j%=n;
            }
            while(v[j]!=-1){
                j++;
                j%=n;
            }
            v[j]=deck[i++];
            gap=0;
        }
        return v;
        
    }
};