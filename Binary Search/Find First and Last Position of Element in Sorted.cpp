/*
Difficulty : Easy
Leetcode: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
can be done in 1 binary search only which looks cleans.
*/

class Solution {
public:
    int bs_first(vector<int> & nums, int s, int e, int target){

        int mid;
        while(s<=e){
            mid = s+(e-s)/2;
            if(nums[mid]==target){
                if( mid > 0 and nums[mid-1]==target){
                    e = mid-1;
                }
                else return mid;
            }
            else if(nums[mid]<target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return -1;
    }

    int bs_last(vector<int> & nums, int s, int e, int target){

        int mid;
        while(s<=e){
            mid = s+(e-s)/2;
            if(nums[mid]==target){
                if( mid+1<nums.size() and nums[mid+1]==target){
                    s = mid+1;
                }
                else return mid;
            }
            else if(nums[mid]<target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> v = {-1,-1};

        int s=0,e=nums.size()-1;

        v[0] = bs_first(nums,s,e,target);
        if(v[0]!=-1)
            v[1] = bs_last(nums,s,e,target);
        return v;
    }
};
