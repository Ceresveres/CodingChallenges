bool has_cycle(SinglyLinkedListNode* head) {
    unordered_set<SinglyLinkedListNode*> set;
    while (head != NULL) {
        if (set.find(head) != set.end()) {
            return 1;
        }
        set.insert(head);
        cout << head->data << endl;
        head = head->next;
    }
    return 0;
}
