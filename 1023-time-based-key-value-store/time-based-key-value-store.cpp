class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {

        vector<pair<string,int>> &v=m[key];
        int lo=0,hi=v.size()-1;
        string val="";
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(v[mid].second<=timestamp){
                val=v[mid].first;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return val;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */