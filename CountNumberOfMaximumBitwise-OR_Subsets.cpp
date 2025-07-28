//2044. Count Number of Maximum Bitwise-OR Subsets
//Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.

//An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.

//The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).



class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int maxx = INT_MIN;
        for(int i=0;i<n;++i){
            total |= nums[i];
        }
        int count = 0,ans=0;
        int totalsub = (1<<n);
        for(int i=0; i<totalsub; ++i){
            ans = 0;
            for(int j=0; j<n; ++j){
                if(i>>j & 1){
                    ans |= nums[j];
                }
            }
            if(ans == total){
                count++;
            }
        } 
        return count;
    }
};
