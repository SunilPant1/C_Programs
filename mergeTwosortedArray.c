struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    // Create a resulting linked list
    struct ListNode* result = NULL;
    
    // If first is null rerurn second
    if (!list1) {
        
        return list2;
    // If second is null return first
    } else if (!list2) {
        
        return list1;
        
    }
    // If first value is less or equal to the second value, result equals the element of the first list
    if (list1->val <= list2->val) {
        
        result = list1;
        // Here we move the result to the next value and call the function again, shifting the list1 value to the next one
        result->next = mergeTwoLists(list1->next, list2);
        
    } else {
        
        result = list2;
        result->next = mergeTwoLists(list1, list2->next);
        
    }
    
    return result;
}