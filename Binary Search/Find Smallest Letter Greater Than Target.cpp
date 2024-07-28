/*
Difficulty : Easy
Concept : Binary search
Leetcode : https://leetcode.com/problems/find-smallest-letter-greater-than-target/

*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char target) {

        int s=0,e=v.size()-1;
        int mid;
        if(target>=v[e])return v[s];
        while(s<=e){
            mid = s+(e-s)/2;
            
            if(v[mid] > target ){
                e = mid-1;
            }
            else if(v[mid] <= target){
                s = mid+1;
            }
        }
        return v[s];
    }
};
