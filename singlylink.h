#ifndef _G_SINGLYLINK_H_
#define _G_SINGLYLINK_H_

struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* n) ：val(x), next(n){}
};

class SinglyLink
{
public:

    ListNode* reverseList(ListNode* head){
        ListNode *l(0), r(head);
        while(r){
            ListNode* c = r;
            r = r->next;
            c->next = l;
            l = c;
        }
        return l;
    }
    
    ListNode* mergeTowLists(ListNode* list1, ListNode* list2){
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode *ret = list1->val <= list2->val ? list1 : list2;
        ListNode *cur = new ListNode();
        while (list1 && list2){
            if (list1->val <= list2->val){
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            } 
            cur = cur->next;
        }

        cur->next = list1 ? list1 : list2;
        return ret;
    }

    bool isPalindrome(ListNode *head){
        ListNode *s(head), *f(head);
        
        while (f && f->next){
            f = f->next->next;
            s = s->next;
        }
        if (f)
            s = s->next;
        s = reverserList(s);
        f = head;
        while (s){
            if (s->val != f->val)
                return false;
            s = s->next;
            f = f->next;
        }
        return true;
    }

    bool hasCycle(ListNode* head){
        ListNode *f(head), *s(head);
        
        while (f && f->next){
            f = f->next->next;
            s = s->next;
            if(f == s)
                return true;
        }

        return false;
    }

};


#endif // _G_SINGLYLINK_H_
