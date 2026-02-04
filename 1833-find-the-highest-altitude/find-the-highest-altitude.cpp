class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int n=gain.size();
        vector<int> v;
        v.push_back(0);
        for(int i=0;i<n;i++){
            // x-v.back()=gain[i]
            v.push_back(v.back()+gain[i]);
        }
        return *max_element(v.begin(),v.end());
    }
};