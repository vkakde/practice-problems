#include <iostream>
#include <conio.h>
#include<string>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l1_curr = l1;
        ListNode *l2_curr = l2;
        
        ListNode *res = new ListNode(0);
        ListNode *res_curr = res;
        
        if(l1==NULL){
            return l2;
        }
        
        if(l2==NULL){
            return l1;
        }        
        
        while(l1_curr!=NULL && l2_curr!=NULL){
            if(l1_curr->val <= l2_curr->val){ 
                res_curr->next = new ListNode(l1_curr->val);
                l1_curr = l1_curr->next;
            }
            else{ 
                res_curr->next = new ListNode(l2_curr->val);
                l2_curr = l2_curr->next;
            }
            res = res_curr->next;
        }
        
        while(l1_curr!=NULL){
            res_curr->next = new ListNode(l1_curr->val);
            l1_curr = l1_curr->next;
        }
        
        while(l2_curr!=NULL){
            res_curr->next = new ListNode(l2_curr->val);
            l2_curr = l2_curr->next;
        }
        
        return res->next;
    }
};

int main(){
    Solution s;

    s.mergeTwoLists(new ListNode(1), new ListNode(2));

    return 0;
}