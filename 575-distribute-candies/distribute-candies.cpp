class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        unordered_map<int,int> m;
        int n=candyType.size();
        for(int i=0;i<n;i++){
            m[candyType[i]]++;
        }
        int sz=m.size();
        return min(n/2,sz);
        
    }
};