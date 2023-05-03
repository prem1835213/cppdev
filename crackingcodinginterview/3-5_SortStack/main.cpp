#include <stack>
#include <iostream>

/*
    Design a method of sorting a stack such that the smallest numbers appear at the top.
    You are only allowed to use one other stack and cannot put data into any other data structure.
*/

void rearrangeStacks(std::stack<int>& nums, std::stack<int>& temp){
    int numPopped = 0;
    int topNums = nums.top();
    nums.pop();
    while (temp.size() > 0 && topNums < temp.top()){
        nums.push(temp.top());
        temp.pop();
        numPopped++;
    }
    temp.push(topNums);
    for (int i = 0; i < numPopped; i++){
        temp.push(nums.top());
        nums.pop();
    }
    return;
}

void sortStack(std::stack<int>& nums){
    std::stack<int> temp;
    if (nums.size() <= 1) return;
    temp.push(nums.top());
    nums.pop();

    while (nums.size() > 0){
        if (nums.top() >= temp.top()){
            temp.push(nums.top());
            nums.pop();
        }
        else{
            rearrangeStacks(nums, temp);
        }
    }

    while (temp.size() > 0){
        nums.push(temp.top());
        temp.pop();
    }

    return;
}

int main(){
    std::stack<int> nums;
    nums.push(2);
    nums.push(3);
    nums.push(4);
    int n = nums.size();
    sortStack(nums);

    // should print 2 3 4
    for (int i = 0; i < n; i++){
        std::cout << nums.top() << " ";
        nums.pop();
    }
    std::cout << std::endl;
}
