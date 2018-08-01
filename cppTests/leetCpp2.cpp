#include "iostream"

/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of 
their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807. 

*/
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * sumLL = new ListNode(0);
        int sum;
        
        if (l1 == NULL || l2 == NULL) {
            return NULL;
        }
        
        while(l1 != NULL)
        {
            
            if (l2 == NULL) {
                /* code */
            }
            
            sum = l1->val + l2->val;
            int carry = sum/10;
            int digit = sum%10;
            sumLL->val = digit;

        }
    }
};

ListNode* constructLL()
{
    int count;
    std::cin >> count;
    int value;
    ListNode* temp = NULL;
    for(size_t i = 0; i < count; i++)
    {
        std::cin>>value;
        ListNode* L1 = new ListNode(value);
        if(0 != i){
            L1->next = temp; 
        }       
        temp = L1;
     }
     return temp;       
}
void printLL(ListNode *L1)
{
    std::cout<<"Print LL"<<std::endl;
    while(L1 != NULL){
        std::cout<<L1->val<<std::endl;
        L1 = L1->next;
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    ListNode *L1 = constructLL();
    printLL(L1);
    return 0;
}
