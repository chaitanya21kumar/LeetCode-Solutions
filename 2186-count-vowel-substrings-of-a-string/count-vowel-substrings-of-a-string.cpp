class Solution {
public:
    bool isvowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    int f(int start,int end,string &word){
        map<char,int> m;
        int cd=0;
        int k=start;
        int ans=0;
        for(int i=start;i<end;i++){

            if(m[word[i]]==0){
                cd++;
            }
            m[word[i]]++;

            while(cd==5){
                m[word[k]]--;
                if(m[word[k]]==0) cd--;
                k++;
            }
            ans+=(k-start);
        }
        return ans;
    }
    int countVowelSubstrings(string word) {

        int n=word.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(isvowel(word[i])){
                int j=i;
                while(j<n && isvowel(word[j])){
                    j++;
                }
                ans+=f(i,j,word);
                i=j-1;
            }
        }
        return ans;
        
    }
};