class Solution {
public:
    vector<int> ts(vector<vector<int>> &graph,vector<int> &indegree,int nodes){
        vector<int> order;
        queue<int> q;

        for(int i=0;i<nodes;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            order.push_back(curr);

            for(auto &ngbr:graph[curr]){
                indegree[ngbr]--;
                if(indegree[ngbr]==0){
                    q.push(ngbr);
                }
            }
        }

        return order.size()==nodes?order:vector<int>();
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        int gid=m;
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i]=gid++;
            }
        }

        int tg=gid; // total groups

        vector<vector<int>> ig(n); // item graph
        vector<int> ii(n,0); // iteam indegree

        vector<vector<int>> gg(tg);
        vector<int> gi(tg,0);

        for(int ci=0;ci<n;ci++){
            for(auto &pi:beforeItems[ci]){

                ig[pi].push_back(ci);
                ii[ci]++;

                int pg=group[pi];
                int cg=group[ci];

                if(pg!=cg){
                    gg[pg].push_back(cg);
                    gi[cg]++;
                }

            }
        }

        vector<int> io=ts(ig,ii,n); // indegree order, item indegree, topo sort
        vector<int> go=ts(gg,gi,tg); // group order, group indegree, topo sort

        if(io.empty() || go.empty()) return {};

        vector<vector<int>> oiig(tg); // ordered items in group
        for(auto &i:io){
            oiig[group[i]].push_back(i);
        }

        vector<int> ans;
        for(auto &g:go){
            for(auto &i:oiig[g]){
                ans.push_back(i);
            }
        }

        return ans;

    }
};