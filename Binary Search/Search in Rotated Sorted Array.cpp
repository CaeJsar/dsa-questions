/*
- difficulty: Medium
- can be easy if you you rotated array and peak element(highest and lowest) concept
- carefully assign start end in while loop
leetcode: https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

class Solution {
public:

    int bs(vector<int> &nums, int s, int e, int target){

        int mid;

        while(s<=e){

            mid = s+(e-s)/2;

            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                s = mid+1;
            else
                e = mid-1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        int s=0,e = nums.size()-1;
        int mid,a,b;

        while(s<e){

            mid = s+(e-s)/2;

            if(nums[mid]>nums[e]){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        
        a = bs(nums,0,s-1,target);
        if(a==-1)
            b = bs(nums,s,nums.size()-1,target);
            return b;
        return a;
    }
};
