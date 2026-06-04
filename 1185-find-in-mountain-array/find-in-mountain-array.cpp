/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int f1(int t,int ii,MountainArray &mountainArr){
        int lo=0;
        int hi=ii;
        int ans=-1;

        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            int x=mountainArr.get(mid);
            if(x==t){
                ans=mid;
                break;
            }
            else if(t>x) lo=mid+1;
            else hi=mid-1;
        }
        return ans;
    }
    int f2(int t,int ii,MountainArray &mountainArr){
        int lo=ii;
        int hi=mountainArr.length()-1;
        int ans=-1;

        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            int x=mountainArr.get(mid);
            if(x==t){
                ans=mid;
                break;
            }
            else if(t>x) hi=mid-1;
            else lo=mid+1;
        }
        return ans;
    }
    int findInMountainArray(int t, MountainArray &mountainArr) {

        int lo=1;
        int hi=mountainArr.length()-2;
        int ii=-1;

        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            int curr=mountainArr.get(mid);
            int prev=mountainArr.get(mid-1);
            int next=mountainArr.get(mid+1);

            if( (prev<curr) && (curr>next) ){
                ii=mid;
                break;
            }
            else if( prev<curr ){
                lo=mid+1;
            }
            else hi=mid-1;
        }

        int x1=f1(t,ii,mountainArr);
        if(x1!=-1) return x1;
        int x2=f2(t,ii,mountainArr);
        if(x2!=-1) return x2;
        return -1;
        
    }
};