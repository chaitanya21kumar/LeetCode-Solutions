class Solution {
public:
    string addBinary(string a, string b) {

        string ans="";
        int i=a.size()-1;
        int j=b.size()-1;
        int c=0;
        while(i>=0 && j>=0){
            if(a[i]=='1' && b[j]=='1'){
                if(c==0){
                    ans='0'+ans;
                    c=1;
                }
                else{
                    ans='1'+ans;
                    c=1;
                }
            }
            else if( (a[i]=='0' && b[j]=='1') || ( a[i]=='1' && b[j]=='0' ) ){
                if(c==0){
                    ans='1'+ans;
                }
                else{
                    ans='0'+ans;
                    c=1;
                }
            }
            else if( a[i]=='0' && b[j]=='0' ){
                if(c==0){
                    ans='0'+ans;
                }
                else{
                    ans='1'+ans;
                    c=0;
                }
            }
            i--;
            j--;
            
        }

        while(i>=0){
            if(a[i]=='1'){
                if(c==1){
                    ans='0'+ans;
                    c=1;
                }
                else{
                    ans='1'+ans;
                }
            }
            else if(a[i]=='0'){
                if(c==1){
                    ans='1'+ans;
                    c=0;
                }
                else{
                    ans=a[i]+ans;
                }
            }
            
            i--;
        }
        while(j>=0){

            if(b[j]=='1'){
                if(c==1){
                    ans='0'+ans;
                    c=1;
                }
                else{
                    ans='1'+ans;
                }
            }
            else if(b[j]=='0'){
                if(c==1){
                    ans='1'+ans;
                    c=0;
                }
                else{
                    ans=b[j]+ans;
                }
            }
            
            j--;
        }
        if(c==1){
            ans='1'+ans;
        }
        return ans;
        
    }
};