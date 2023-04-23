#include <vector>
#include <iostream>

class Solution{
public:
    int removeDuplicates(std::vector<int>& nums){
        if (nums.size() == 1){
            return 1;
        }

        bool seen[201] = {}; // -100 <= nums[i] <= 100

        int i = 0;
        int numUnique = 0;
        while (i < nums.size()){
            int hash = 100 - nums[i];
            if (!seen[hash]){
                seen[hash] = true;
                i++;
                numUnique++;
            }
            else{
                int j = i;
                while (j < nums.size() && nums[j] == nums[i]){
                    j++;
                }
                if (j < nums.size()){
                    nums[numUnique] = nums[j];
                    hash = 100 - nums[j];
                    seen[hash] = true;
                    numUnique++;
                }
                i = j;
            }
        }

        return numUnique;

    }
};

int main(){

    std::vector<int> nums = {1, 1, 2, 3, 4, 5, 5, 6}; // should become [1, 2, 3, 4, 5, 6, ., .]

    Solution sol;
    int numUnique = sol.removeDuplicates(nums);
    std::cout << numUnique << " should be 6" << std::endl;
    for (int i = 0; i < 6; i++){
        std::cout << " nums[" << i << "]: " << nums[i] << " should be " << i+1 << std::endl;
    }
}