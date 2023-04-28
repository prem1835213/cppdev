#include <unordered_set>
#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){}
    ListNode(int x) : val(x){}
    ListNode(int x, ListNode* node) : val(x), next(node){}
};

ListNode* removeDuplicates(ListNode* head){
    if (!head){
        return head;
    }

    std::unordered_set<int> seenVals;
    ListNode* cur = head;
    seenVals.insert(cur->val);
    while (cur->next){
        ListNode* temp = cur->next;
        if (seenVals.find(temp->val) == seenVals.end()){
            seenVals.insert(temp->val);
            cur = cur->next;
        }
        else{
            cur->next = temp->next;
            if (cur->next) cur = cur->next;
        }
    }

    return head;

}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* one = new ListNode(1);
    ListNode* three = new ListNode(3);

    head->next = three;
    three->next = one;

    head = removeDuplicates(head);

    while (head){
        std::cout << head->val;
        head = head->next;
    }
    std::cout << std::endl;

    delete three;
    delete one;
    delete head;
}