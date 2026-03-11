class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> s;
        for(int i=0;i<arr1.size();i++){
            int num=arr1[i];
            while(s.find(num)==s.end() && num>0){
                s.insert(num);
                num/=10;
            }
        }

        int ans=0;
        for(int i=0;i<arr2.size();i++){
            int n=arr2[i];
            while(n>0 && s.find(n)==s.end()){
                n/=10;
            }

            if(n>0){
                int x=(int)log10(n)+1;
                ans=max(ans,x);
            }

        }
        return ans;
        
    }
};