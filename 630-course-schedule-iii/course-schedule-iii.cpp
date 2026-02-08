class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {

        int n=courses.size();
        sort(courses.begin(),courses.end(),comp);
        priority_queue<int> pq;
        int t=0,ans=0;
        for(int i=0;i<n;i++){
            int d=courses[i][0];
            int l=courses[i][1];
            t+=d;
            pq.push(d);
            if(t>l){
                t-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
        
    }
};