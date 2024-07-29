/*
Difficulty : easy-medium for me
use other concepts of binary search like peak in mountain array & also uses optimization for api calling
leetcode : https://leetcode.com/problems/find-in-mountain-array/
*/

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

    int bs(MountainArray &mountarr,int s, int e, int target){

        int mid;
        int x ;
        bool order = mountarr.get(s)<mountarr.get(e);
        while(s<=e){
            mid = s+(e-s)/2;
            x = mountarr.get(mid);
            if(x==target){
                return mid;
            }
            if(order)
                if( x < target){
                    s = mid+1;
                }
                else {
                    e = mid-1;
                }
            else{
                if( x < target){
                    e = mid-1;
                }
                else {
                    s = mid+1;
                }
            }
        }
        return -1;
    }


    int findInMountainArray(int target, MountainArray &mountarr) {
        
        int s=0, e=mountarr.length()-1;
        int mid,peak=-1,a,b,x;

        while(s<=e){
            mid = s+(e-s)/2;
            x = mountarr.get(mid);

            if(x<mountarr.get(mid+1) ){
                s = mid+1;
            }
            else if(x<mountarr.get(mid-1) ){
                e = mid-1;
            }
            
            else {
                peak = mid;
                break;
            }

        }

        a = bs(mountarr,0,peak,target);
        if(a==-1){
            b = bs(mountarr,peak+1,mountarr.length()-1,target);
        }
        else return a;
        
        if(a==-1)return b;
        if(b==-1)return a;
        return min(a,b);
        
    }
};
