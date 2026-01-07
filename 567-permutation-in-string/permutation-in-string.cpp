class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1=s1.size(),n2=s2.size();
        map<char,int> m;
        for(int i=0;i<n1;i++) m[s1[i]]++;

        for(int i=0;i<=n2-n1;i++){
            map<char,int> m2;
            for(int j=i;j<=i+n1-1;j++){
                m2[s2[j]]++;
            }
            if(m==m2) return true;
        }
        return false;




        
    }
};