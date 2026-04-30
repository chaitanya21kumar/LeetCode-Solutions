class Solution {
public:
    int addDigits(int num) {


        while(num>9){
            int x=num;
            int s=0;
            while(x>0){
                int ld=x%10;
                x/=10;
                s+=ld;
            }
            num=s;
        }
        return num;


        
    }
};