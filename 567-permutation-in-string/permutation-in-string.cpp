class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1=s1.size(),n2=s2.size();

        vector<int> f1(26,0),f2(26,0);

        for(int i=0;i<n1;i++){
            f1[s1[i]-'a']++;
        }

        int l=0,r=0;

        while(r<n2){
            f2[s2[r]-'a']++;
            if(r-l+1>n1){
                f2[s2[l]-'a']--;
                l++;
            }
            r++;

            if(f1==f2) return true;
        }
        return false;
        
    }
};