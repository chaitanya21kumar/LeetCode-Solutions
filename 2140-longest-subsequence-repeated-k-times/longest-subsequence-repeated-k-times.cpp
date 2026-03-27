class Solution {
public:
    string ans="";
    bool isSub(string s,string cur,int k){
        int i=0,j=0;
        int n=s.length();
        int l=cur.length();
        while(i<n && j<k*l){
            if(s[i]==cur[j%l]) j++;
            i++;
        }
        if(j==k*l) return true;
        return false;
    }
    void f(string s,int n,int k,string cur,int mx,vector<int> &v,vector<int> &rf){
        if(cur.length()>mx) return;
        if( ((cur.length()>ans.length()) || (cur.length()==ans.length() && cur>ans)) && isSub(s,cur,k) ){
            ans=cur;
        }

        for(int i=0;i<26;i++){
            if(v[i]==1 && rf[i]>0){
                char ch=(i+'a');
                cur=cur+ch;
                rf[i]--;

                f(s,n,k,cur,mx,v,rf);

                cur.pop_back();
                rf[i]++;
            }
        }

    }
    string longestSubsequenceRepeatedK(string s, int k) {

        int n=s.length();
        vector<int> v(26,1);
        vector<int> freq(26,0);
        vector<int> rf(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]<k) v[i]=0;
            else{
                rf[i]=freq[i]/k;
            }
        }
        int mx=n/k;
        f(s,n,k,"",mx,v,rf);
        return ans;

    }
};