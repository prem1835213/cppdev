#include <iostream>

/*
    Given a singly linked list and a target value,
    partition the list such that all values less than the target come before
    all of the values greater than or equal to the target.

    Eg: 
    Input: 3 -> 1 -> 5 -> 4 -> 6, target = 5
    Output: 3 -> 1 -> 4 -> 6 -> 5

    The output can be in any order as long as all values <= target come before all values >= target.
*/

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){}
    ListNode(int x) : val(x){}
    ListNode(int x, ListNode* node) : val(x), next(node){}
};

ListNode* partition(ListNode* head, int val){

    if (!head){
        return head;
    }

    ListNode* headLess = head;
    ListNode* headGreat = head;
    ListNode* curLess = head;
    ListNode* curGreat = head;
    ListNode* cur = head;
    cur = head;
    if (cur->val < val){
        headLess = cur;
        curLess = headLess;
        while (curLess->next && curLess->next->val < val){
            curLess = curLess->next;
        }
        headGreat = curLess->next;
        curGreat = headGreat;
        cur = headGreat;
    }
    else{
        headGreat = cur;
        curGreat = headGreat;
        while (curGreat->next && curGreat->next->val >= val){
            curGreat = curGreat->next;
        }
        headLess = curGreat->next;
        curLess = headLess;
        cur = headLess;
    }
    
    // return head;
    if (!headGreat || !headLess){
        return head;
    }

    while (cur->next){
        if (cur->next->val < val){
            curLess->next = cur->next;
            curLess = curLess->next;
        }
        else{
            curGreat->next = cur->next;
            curGreat = curGreat->next;
        }
        cur = cur->next;
    }
    curGreat->next = cur->next;
    curLess->next = headGreat;
    
    return headLess;
}

int main(){
    ListNode* three = new ListNode(3);
    ListNode* one = new ListNode(1);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(5);
    ListNode* six = new ListNode(6);
    ListNode* eight = new ListNode(8);

    // 3 -> 1 -> 5 -> 4 -> 6 -> 8
    three->next = one;
    one->next = five;
    five->next = four;
    four->next = six;
    six->next = eight;

    ListNode* head = three;
    head = partition(head, 5);

    while (head){
        std::cout << head->val;
        head = head->next;
    }
    std::cout << std::endl;

    delete three;
    delete one;
    delete four;
    delete five;
    delete six;
    delete eight;
}