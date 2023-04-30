#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){}
    ListNode(int x) : val(x){}
    ListNode(int x, ListNode* node) : val(x), next(node){}
};

/*
    Determine if two singly linked lists "intersect"
    Two SLLs intersect if there is some k in list 1 and some j in list 2
    such that list1[k] and list2[j] are equal by reference
*/

std::pair<int, int> getLengths(ListNode* head1, ListNode* head2){
    auto* cur = head1;
    int length1 = 0;
    int length2 = 0;
    while (cur){
        length1++;
        cur = cur->next;
    }
    cur = head2;
    while (cur){
        length2++;
        cur = cur->next;
    }
    std::pair<int, int> lengthPair = std::make_pair(length1, length2);
    return lengthPair;
}

bool intersection(ListNode* head1, ListNode* head2){
    if (!head1 || !head2) return false;

    std::pair<int, int> lengthPair = getLengths(head1, head2);
    ListNode* curLong;
    ListNode* curShort;
    int delta;
    if (lengthPair.first > lengthPair.second){
        curLong = head1;
        curShort = head2;
        delta = lengthPair.first - lengthPair.second;
    }
    else{
        curLong = head2;
        curShort = head1;
        delta = lengthPair.second - lengthPair.first;
    }


    for (int i = 0; i < delta; i++){
        curLong = curLong->next;
    }

    while (curLong){
        if (curLong == curShort) return true;
        curLong = curLong->next;
        curShort = curShort->next;
    }
    
    return false;
}

int main(){
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* seven = new ListNode(7);
    ListNode* two = new ListNode(2);
    ListNode* six = new ListNode(6);
    ListNode* five = new ListNode(5);
    ListNode* one1 = new ListNode(1);
    ListNode* one2 = new ListNode(1);

    three->next = four;
    four->next = seven;
    seven->next = two;
    two->next = six;

    five->next = two;
    
    // 3 - 4 - 7 - 2 - 6
    //         5 - ^
    std::cout << ((int) intersection(three, five) == 1) << std::endl;

    five->next = one1;
    five->next = one2;
    
    // 3 - 4 - 7 - 2 - 6
    //         5 - 1 - 1
    std::cout << ((int) intersection(three, five) == 0) << std::endl;

    delete three;
    delete four;
    delete seven;
    delete two;
    delete six;
    delete five;
    delete one1;
    delete one2;

}