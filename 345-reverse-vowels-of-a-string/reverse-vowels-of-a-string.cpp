class Solution {
public:
    string reverseVowels(string s) {

        int n=s.size();
        string v="";
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
                v=v+ch;
            }
        }
        reverse(v.begin(),v.end());
        int j=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
                s[i]=v[j++];
            }
        }
        return s;
        
    }
};