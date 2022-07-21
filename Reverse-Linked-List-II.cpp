//Reverse Linked List II

//Given the head of a singly linked list and two integers left and right where left <= right,
//reverse the nodes of the list from position left to position right, and return the reversed list.

//Input: head = [1,2,3,4,5], left = 2, right = 4
//Output: [1,4,3,2,5]


 ListNode* reverseBetween(ListNode* head, int left, int right) {
         if(head == NULL || left == right){
            return head;
        }
        ListNode* prev, *tail = NULL, *temp = NULL;
        ListNode dummy(NULL);
        prev = &dummy;
        dummy.next = head;
        for(int i=0; i < left-1; i++){
            prev = prev->next;
        }
        tail = prev->next;
        for(int i=0; i< right - left;i++){
            temp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = temp; 
        }
        
        return dummy.next;
    }
