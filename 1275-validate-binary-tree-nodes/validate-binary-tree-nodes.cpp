class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {

        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){

            if(lc[i]!=-1){
                indeg[lc[i]]++;
                if(indeg[lc[i]]>1) return false;
            }
            if(rc[i]!=-1){
                indeg[rc[i]]++;
                if(indeg[rc[i]]>1) return false;
            }

        }

        int c=0;
        int root=-1;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                c++;
                root=i;
            }
        }

        if(c>1 || c==0) return false;

        queue<int> q;
        q.push(root);
        vector<int> vis(n,0);
        vis[root]=1;
        int cn=0;

        while(!q.empty()){
            auto x=q.front();
            q.pop();
            cn++;
            
            int lci=lc[x];
            int rci=rc[x];

            if(lci!=-1){
                if(vis[lci]==0){
                    q.push(lci);
                    vis[lci]=1;
                }
                else return false;
            }

            if(rci!=-1){
                if(vis[rci]==0){
                    q.push(rci);
                    vis[rci]=true;
                }
                else return false;
            }


        }

        return cn==n;
        
    }
};