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
class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        for(int i=0;i<n;i++){
            if(lists[i]!=nullptr){
                pq.push(lists[i]);
            }
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* ans=dummy;
        while(!pq.empty()){
            ListNode* curr=pq.top();
            pq.pop();
            ans->next=curr;
            ans=ans->next;
            if(curr->next!=nullptr){
                pq.push(curr->next);
            }
        }
        return dummy->next;
    }
};