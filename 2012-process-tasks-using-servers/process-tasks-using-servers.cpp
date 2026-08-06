class Solution {
public:
    typedef pair<int,int> s; // server
    typedef pair<int,s> bs; // busy server
    typedef long long int ll;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<s,vector<s>,greater<s>> fs; // free servers
        priority_queue<bs,vector<bs>,greater<bs>> bss; // busy servers

        int n=servers.size();
        int m=tasks.size();
        for(int i=0;i<n;i++){
            fs.push({servers[i],i});
        }
        vector<int> ans;
        ll ct=0;
        for(int j=0;j<m;j++){
            ct=max(ct,(ll)j);
            while(!bss.empty() && bss.top().first<=ct){
                fs.push(bss.top().second);
                bss.pop();
            }
            if(fs.empty()){
                ct=bss.top().first;
                while(!bss.empty() && bss.top().first<=ct){
                    fs.push(bss.top().second);
                    bss.pop();
                }
            }
            s b=fs.top();
            fs.pop();
            int w=b.first;
            int i=b.second;
            ans.push_back(i);

            ll ft=ct+tasks[j];
            bss.push({ft,{w,i}});
        }
        return ans;


    }
};