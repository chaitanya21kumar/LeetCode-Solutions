class Solution {
public:
    int score(vector<string>& cards, char x) {

        int n=cards.size();
        vector<int> sx(26),ex(26);

        int smx=0,mx=0,sex=0,emx=0,cxx=0;
        for(int i=0;i<n;i++){
            string s=cards[i];
            if(s[0]==x && s[1]==x){
                cxx++;
                continue;
            }
            if(s[0]==x){
                sx[s[1]-'a']++;
                smx++;
                if(sx[s[1]-'a']>mx){
                    mx=sx[s[1]-'a'];
                }
            }
            else if(s[1]==x){
                ex[s[0]-'a']++;
                if(ex[s[0]-'a']>emx){
                    emx=ex[s[0]-'a'];
                }
                sex++;
            }
        }

        int ans=0;
        for(int k=0;k<=cxx;k++){
            int rem=cxx-k;
            
            int sumx=smx+k;
            int mxf=max(mx,k);
            int p1=min(sumx-mxf,sumx/2);

            int sumex=sex+rem;
            int mxfe=max(emx,rem);
            int p2=min(sumex-mxfe,sumex/2);

            ans=max(ans,p1+p2);
        }
        
        return ans;
        
    }
};