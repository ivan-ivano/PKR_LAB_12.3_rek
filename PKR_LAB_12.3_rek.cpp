#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* n) {
    if (n == NULL) {
        cout << endl;
        return;
    }
    cout << n->data << " ";
    printList(n->next);
}

void insertAfterValue(Node** head_ref, int target_data, int new_data) {
    if (*head_ref == NULL) {
        return;
    }
    if ((*head_ref)->data == target_data) {
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->next = (*head_ref)->next;
        (*head_ref)->next = new_node;
        insertAfterValue(&((*head_ref)->next->next), target_data, new_data);
    }
    else {
        insertAfterValue(&((*head_ref)->next), target_data, new_data);
    }
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    cout << "Original list: ";
    printList(head);

    int v1 = 2;
    int v2 = 5;
    cout << "Inserting " << v2 << " after " << v1 << ": ";
    insertAfterValue(&head, v1, v2);

    cout << "Updated list: ";
    printList(head);

    return 0;
}
