/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/

 struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode;
        auto curr = head, pre = head;
        bool cap = false;
         if(cap)
            {
                curr -> val = 1; 
                cap = false;
            }
        
            curr -> val += l1 -> val + l2 -> val;
            if(curr ->val >= 10)
            {
                curr ->val -= 10;
                cap = true;
            }       
            l1 = l1 -> next;
            l2 = l2 -> next;
        while(l1!= nullptr && l2!=nullptr)
        {
            auto next = new ListNode;
            if(cap)
            {
                next -> val = 1; 
                cap = false;
            }
        
            next -> val += l1 -> val + l2 -> val;
            if(next ->val >= 10)
            {
                next ->val -= 10;
                cap = true;
            }
            curr -> next = next;
            pre = curr;
            curr = curr -> next;
            pre -> next = curr;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(l1 != nullptr)
        {
            auto next = new ListNode;
            if(cap)
            {
                next -> val = 1; 
                cap = false;
            }
            next -> val += l1 ->val;
             if(next ->val >= 10)
            {
                next ->val -= 10;
                cap = true;
            }
            curr -> next = next;
            pre = curr;
            curr = curr -> next;
            pre -> next = curr;
            l1 = l1 -> next;

        }

        while(l2 != nullptr)
        {
            auto next = new ListNode;
             if(cap)
            {
                next -> val = 1; 
                cap = false;
            }
            next -> val += l2 ->val;
             if(next ->val >= 10)
            {
                next ->val -= 10;
                cap = true;
            }
            curr -> next = next;
            pre = curr;
            curr = curr -> next;
            pre -> next = curr;
            l2 = l2 -> next;
        }
        if(cap)
        {
            curr -> next = new ListNode(1);
            curr = curr -> next;
        }
        if(curr -> val == 0)
        {
            pre -> next =nullptr;
            curr = nullptr;
        }

        return head;
    }
};