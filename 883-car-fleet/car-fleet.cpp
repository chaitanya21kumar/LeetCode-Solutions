class Solution {
public:
    static bool cmp(pair<int,double> &a,pair<int,double> &b){
        return a.first>b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n=position.size();
        vector<pair<int,double>> v; // {dist,speed}

        for(int i=0;i<n;i++) v.push_back({position[i],speed[i]});

        sort(v.begin(),v.end(),cmp);
        vector<double> st;

        for(int i=0;i<n;i++){

            double t=(target-v[i].first)/(v[i].second);
            st.push_back(t);

            if(st.size()>=2){
                double sl=st.back();
                double l=st[st.size()-2];
                if(sl<=l){
                    st.pop_back();
                }
            }

        }

        return st.size();

        
    }
};