/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1,l2,0);
         
    }
    ListNode* add(ListNode* l1,ListNode* l2, int car){
        if(l1==nullptr &&  l2==nullptr &&  car==0){
            return nullptr;
        }
        int sum=car;
        if(l1) sum+=l1->val;
        if(l2) sum+=l2->val;
        ListNode* node=new ListNode(sum%10);{
            node->next=add(l1?l1->next:nullptr,l2?l2->next:nullptr,sum/10);
            return node;
        }
    }
};
     ListNode* temp=new ListNode(-1);
//      ListNode *head=temp;
// int car=0;
// while(l1==nullptr &&  l2==nullptr &&  car==0){
//         int sum=0;
        
//         if(l1!=nullptr) sum+=l1->val;
//         l1=l1->next;
//           if(l2!=nullptr) sum+=l1->val;
//         l2=l2->next;
//         sum+=car;
//         temp->next=new ListNode(sum%10);
//         temp=temp->next;
//         car=sum/10;
//         return head->next;
// }
//     }
//     };
