#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if (!list1 && !list2){
            return list1;
        }
        else if (!list1){
            return list2;
        }
        else if (!list2){
            return list1;
        } 

        ListNode* head;
        ListNode* cur;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        if (cur1->val < cur2->val) {
            head = cur1;
            cur1 = cur1->next;
        }
        else{
            head = cur2;
            cur2 = cur2->next;
        }
        cur = head;

        while (cur1 && cur2){
            if (cur1->val < cur2->val){

                cur->next = cur1;
                cur1 = cur1->next;
            }
            else{
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        
        if (cur1){
            cur->next = cur1;
        }
        else{
            cur->next = cur2;
        }

        return head;
    }
};

int main(){
    Solution sol;

    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(5);

    one->next = three;
    three->next = five;

    two->next = four;

    std::cout << "List 1:" << std::endl;
    ListNode* cur = one;
    while (cur){
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    std::cout << "List 2:" << std::endl;
    cur = two;
    while (cur){
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    std::cout << "Output:" << std::endl;
    ListNode* head = sol.mergeTwoLists(one, two);
    cur = head;
    while (cur){
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    delete one;
    delete two;
    delete three;
    delete four;
    delete five;

    return 0;
}