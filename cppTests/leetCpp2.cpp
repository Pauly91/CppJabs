#include "iostream"
#include "fstream"
/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of 
their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807. 


Input: (2 -> 4 -> 3) + (5 -> 6)
Output: 7 -> 0 -> 4
Explanation: 342 + 65 = 407. 



Input: (2 -> 4) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 42 + 465 = 507. 

Algorithm:
    - Add the values as we traverse the value, til one of them hits null.
    - Then get the carry and add to the one that did not hit null and c
      compelete it.





*/

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printLL(ListNode *);


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode * sumLL = new ListNode(0);
        ListNode * startNode = sumLL;
        int sum;
        
        if (l1 == NULL || l2 == NULL) {
            return NULL;
        }
        int carry = 0;
        while(l1 != NULL && l2 != NULL)
        {
            
            printLL(startNode);
            printLL(sumLL);
            sum = l1->val + l2->val;
            int digit = sum%10;
            sumLL->val = digit + carry;
            carry = sum/10;

            sumLL->next = new ListNode(0);
            sumLL = sumLL->next;

            l1 = l1->next;
            l2 = l2->next;
        }

            printLL(startNode);
            printLL(sumLL);

        // This is the part to fill the code to add the part
        // the numbers exceed the size;

        ListNode *tmp;
        if(l1 == NULL && l2 != NULL)
            tmp = l2;
        else if(l1 != NULL && l2 == NULL)
            tmp = l1;
        else
        {
            delete sumLL;
            printLL(startNode);
            return startNode;
        }
        while(tmp != NULL)
        {
            sum = tmp->val + carry;
            int digit = sum%10;
            sumLL->val = digit;
            carry = sum/10;

            sumLL->next = new ListNode(0);
            sumLL = sumLL->next;

            tmp = tmp->next;

        }
        return startNode;
    }
private:
    // Need to function to add the remaining LL
    // Need a function to reverse an LL 

    
};

ListNode* constructLL(std::string fileName)
{
    int count;
    int value;
    ListNode* temp = NULL;

    std::ifstream infile;
    infile.open(fileName.data());
    if (!infile) 
    {
        std::cout << "Unable to open file "<< fileName.data()<<std::endl;
        return NULL;    
    }
    infile >> count;
    for(size_t i = 0; i < count; i++)
    {
        infile >> value;
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
    while(L1 != NULL){
        std::cout<<L1->val<<std::endl;
        L1 = L1->next;
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    ListNode *L1 = constructLL("in1");
    ListNode *L2 = constructLL("in2");

    Solution sol1;
    ListNode *sum = sol1.addTwoNumbers(L1,L2);
    printLL(sum);
    return 0;
}
