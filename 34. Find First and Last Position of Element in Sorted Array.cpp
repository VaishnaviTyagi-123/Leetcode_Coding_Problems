//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

//If target is not found in the array, return [-1, -1].

//You must write an algorithm with O(log n) runtime complexity.


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v(2,-1);
        int l=0,h=n-1;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m] == target){
                v[0] = m;
                h = m-1;
            }
            else if(nums[m]>target){
                h = m-1;
            }
            else{
                l=m+1;
            }
        }

        l=0,h=n-1;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m] == target){
                v[1] = m;
                l=m+1;
            }
            else if(nums[m]<target){
                l = m+1;
            }
            else{
                h=m-1;
            }
        }
        return v;
    }
};
