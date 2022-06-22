DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    if (llist->data >= data && llist->prev == NULL) {
        cout << "test case" << endl;
        DoublyLinkedListNode *tmp = new DoublyLinkedListNode(data);
        llist->prev = tmp;
        tmp->next = llist;
        return tmp;
    }
    
    if (llist->next != NULL) {
        cout << llist-> data << endl;
        if ((llist->next->data >= data) && (llist->data <= data)) {
            DoublyLinkedListNode *tmp = new DoublyLinkedListNode(data);
            tmp->prev = llist;
            tmp->next = llist->next;
            llist->next->prev = tmp;
            llist->next = tmp;  
        } else {
            sortedInsert(llist->next, data);
        }
    } else if (data >= llist->data && llist->next == NULL) {
            DoublyLinkedListNode *tmp = new DoublyLinkedListNode(data);
            tmp->prev = llist;
            llist->next = tmp;
            cout << "huh" << endl;
    }

    return llist;
}
