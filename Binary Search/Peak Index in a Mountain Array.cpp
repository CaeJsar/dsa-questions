/*
difficulty : Easy
Leetcode : https://leetcode.com/problems/peak-index-in-a-mountain-array/
->TC O( log(n) )
->New concept found in LC solutions : "Golden-Section-Search" though i dind't understand it
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1;
        int mid;

        while(s<=e){
            mid = s+(e-s)/2;

            if(arr[mid+1]>arr[mid]){
                s = mid+1;
            }
            else if(arr[mid-1]> arr[mid]){
                e = mid-1;
            }
            else{
                return mid;
            }
        }
        return s;
    }
};
