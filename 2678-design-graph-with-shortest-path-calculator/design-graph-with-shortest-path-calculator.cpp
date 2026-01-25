class Graph {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    int sz;
    Graph(int n, vector<vector<int>>& edges) {
        sz=n;
        for(auto &x:edges){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0],v=edge[1],w=edge[2];
        adj[u].push_back({v,w});
    }
    
    int shortestPath(int node1, int node2) {
        typedef pair<int,int> p;
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> dist(sz,INT_MAX);
        dist[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            auto x=pq.top();
            int node=x.second;
            int d=x.first;
            pq.pop();
            for(auto &y:adj[node]){
                int v=y.first;
                int ew=y.second;
                if(d+ew<dist[v]){
                    dist[v]=d+ew;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=dist[node2];
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */