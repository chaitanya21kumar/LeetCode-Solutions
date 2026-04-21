class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {


        int n=arr.size();
        unordered_set<int> s(arr.begin(),arr.end());

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=arr[i];
                int b=arr[j];
                int cl=2;
                int c=(a+b);

                while(s.find(c)!=s.end()){
                    cl++;
                    a=b;
                    b=c;
                    c=a+b;
                }
                ans=max(ans,cl);
            }
        }

        return ans>=3?ans:0;


    }
};