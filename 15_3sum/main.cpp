#include <vector>
#include <algorithm>
#include <iostream>

class Solution{
    public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums){
        std::vector<std::vector<int>> answer;
        std::sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size()){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k && j < nums.size() && k > 0){
                if (nums[i] + nums[j] + nums[k] == 0){
                    answer.push_back({nums[i], nums[j], nums[k]});
                    int temp = nums[k];
                    while (k > 0 && nums[k] == temp){
                        k--;
                    }
                }
                else if (nums[i] + nums[j] + nums[k] > 0){
                    int temp = nums[k];
                    while (k > 0 && nums[k] == temp){
                        k--;
                    }
                }
                else{
                    int temp = nums[j];
                    while (j < nums.size() && nums[j] == temp){
                        j++;
                    }
                }
            }
            int temp = nums[i];
            while (i < nums.size() && nums[i] == temp){
                i++;
            }
        }
        return answer;
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {0, 1, 2, -1, -1, -4};
    std::vector<std::vector<int>> answer = sol.threeSum(nums);

    for(int i = 0; i < answer.size(); i++){
        for (int j = 0; j < answer[i].size(); j++){
            std::cout << answer[i][j] << " ";
        }
        std::cout << std::endl;
    }
}