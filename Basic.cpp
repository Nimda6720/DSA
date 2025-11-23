#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
};

void printList(Node* n) {
    while (n != NULL) {
        cout << n->value << " ";
        n = n->next;
    }
}

void insertAtBeginning(Node** head, int new_value) {
    //1. Prepare a new node
    Node* new_node = new Node();
    new_node->value = new_value;

    //2. Put in the data at the beginning
    new_node->next = *head;

    //3. Move the head to point to the new node
    *head = new_node;
}

void ineserAtEnd(Node** head, int new_value) {
    
    //1. Prepare a new node
    Node* new_node = new Node();
    new_node->value = new_value;
    new_node->next = NULL;
    

    //2. If the Linked List is empty, then make the new node as head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    //3. Else traverse till the last node
    Node* last = *head; //goes to last using clues given by head like in invegtigation
    while (last->next != NULL) {
        last = last->next;
    }

    //4. Change the next of last node
    last->next = new_node;

}

void insertAfter(Node* previous_node, int new_value) {
    
    //1. Check if the given previous_node is NULL
    if (previous_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }

    //2. Prepare a new node
    Node* new_node = new Node();
    new_node->value = new_value;

    //3. Insert the new node after the previous_node
    new_node->next = previous_node->next; //so that we don't lose address of next node
    previous_node->next = new_node;
}
int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;
    
    insertAtBeginning(&head, 0);
    ineserAtEnd(&head, 4);
    insertAfter(second, -2);
    printList(head);
    return 0;
}
