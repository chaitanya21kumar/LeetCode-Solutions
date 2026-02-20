class Solution {
public:
    int strStr(string haystack, string needle) {

        int n1=haystack.size();
        int n2=needle.size();
        for(int i=0;i<n1;i++){
            int j=0;
            int ii=i;
            while(ii<n1 && j<n2 && haystack[ii]==needle[j]){
                ii++;
                j++;
            }
            if(j==n2) return ii-n2;
        }
        return -1;
        
    }
};