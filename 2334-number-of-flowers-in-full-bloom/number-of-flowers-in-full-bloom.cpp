class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        int n=flowers.size();
        int m=people.size();

        vector<int> st,et;
        for(int i=0;i<n;i++){
            st.push_back(flowers[i][0]);
            et.push_back(flowers[i][1]);
        }
        sort(st.begin(),st.end());
        sort(et.begin(),et.end());
        vector<int> ans;
        for(int i=0;i<m;i++){
            int x=people[i];
            int l=upper_bound(st.begin(),st.end(),x)-st.begin();
            int r=lower_bound(et.begin(),et.end(),x)-et.begin();
            ans.push_back(l-r);
        }
        return ans;
        
    }
};