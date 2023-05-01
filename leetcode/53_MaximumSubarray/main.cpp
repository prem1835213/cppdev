#include <vector>
#include <iostream>

/*
    Find the maximum sum of a subarray of contiguous elements of the given array.
*/

class Solution {
    public:
    int maxSubArray(std::vector<int>& nums){
        int n = nums.size();
        int ifPicked[n];
        
        // Dynamic Programming, memoizing from bottom up
        ifPicked[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--){
            ifPicked[i] = std::max(nums[i], nums[i] + ifPicked[i+1]);
        }

        // Return maximum of memoization results
        int maxSum = ifPicked[0];
        for (int i = 1; i < n; i++){
            if (ifPicked[i] > maxSum) maxSum = ifPicked[i];
        }
        return maxSum;
    }
};

int main(){
    std::vector<int> nums = {1, 4, -6, 8, 9, -1, 5};
    Solution sol;

    int maxSum = sol.maxSubArray(nums);
    std::cout << (maxSum == 21) << std::endl;

    nums = {-1, -4};
    maxSum = sol.maxSubArray(nums);
    std::cout << (maxSum == -1) << std::endl;
}