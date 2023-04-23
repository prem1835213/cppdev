#include <algorithm>
#include <vector>
#include <iostream>

class Solution{
public:
    /*
        Removes all occurrences of val in-place.
        Moves all occurrences of non-val elements to the front of nums.
        Order does not matter.

        Returns number of non-val elements in nums
    */
    int removeElement(std::vector<int>& nums, int val){
        std::sort(nums.begin(), nums.end());
        // find first and last occurrence of val (left and right)
        int left = 0;
        while (left < nums.size() && nums[left] != val){left++;}
        int right = left;
        while (right < nums.size() && nums[right] == val){right++;}

        // move everything after the last occurrence of val over by (# of val) places
        while (right < nums.size()){
            nums[left] = nums[right];
            left++;
            right++;
        }
        return left;
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int expectedNumNotVal = 5;
    int returnedNumNotVal = sol.removeElement(nums, val);

    std::cout << "Function returned " << returnedNumNotVal << " should be " << expectedNumNotVal << std::endl;
    for (int i = 0; i < expectedNumNotVal; i++){
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}