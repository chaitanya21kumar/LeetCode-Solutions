class Solution {
public:
    string answerString(string word, int f) {

        if(f==1) return word;
        int n=word.size();
        int i=0,j=i+1,k=0;
        while(j+k<n){
            if(j+k<n && word[i+k]==word[j+k]){
                k++;
            }
            else if(j+k<n && word[i+k]>word[j+k]){
                j+=k+1;
                k=0;
            }
            else if(j+k<n && word[i+k]<word[j+k]){
                i=j;
                j+=1;
                k=0;
            }
        }
        int mn=min(n-i,n-(f-1));
        return word.substr(i,mn);
        
    }
};