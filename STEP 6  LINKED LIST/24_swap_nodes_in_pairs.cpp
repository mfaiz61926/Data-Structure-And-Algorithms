class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* temp = sec;
        ListNode* prev = NULL;   // added
        bool ok = true;

        while(first && sec && ok){
            first->next = sec->next;
            sec->next = first;

            if(prev) prev->next = sec;  // connect previous pair
            prev = first;               // move prev
            first = first->next;

            if(first) sec = first->next;
            else ok = false;
        }

        return temp;
    }
};