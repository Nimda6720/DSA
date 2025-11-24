#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtBeginning(Node** head, int new_value) {
    Node* newNode = new Node();
    newNode->value = new_value;
    newNode->next = *head; //New node points forward to old head
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode; //head points backward to the newNode.
    }

    *head = newNode;
}

void insertAtEnd(Node** head, int new_value) {
    Node* newNode = new Node();
    newNode->value = new_value;
    newNode->next = NULL;
    
    // Not really needed in the grand scheme of things
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    // Not really needed in the grand scheme of things

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; // Move forward to the last node
    }

    temp->next = newNode; // making last node point to new node
    newNode->prev = temp; // New node points backward to last node
}

void insertAtPosition(Node** head, int new_value, int position) {
    if (position == 1) {
        insertAtBeginning(head, new_value);
        return;
    }

    Node* newNode = new Node();
    newNode->value = new_value;

    Node* temp = *head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    //Here temp is pointing to the node after which new node is to be inserted, meaning now temp points to (n-1) th node

    //not needed in the grand scheme of things
    if (temp == NULL) {
        cout << "Position out of range" << endl;
        delete newNode;
        return;
    }
    //not needed in the grand scheme of things

    newNode->next = temp->next; //visualize it as a empty bubble being created between two nodes, and we are putting out newNode in that bubble
    newNode->prev = temp; //as newNode's previous points to temp

    if (temp->next != NULL) {
        temp->next->prev = newNode; //making our newNode as previous (..pause for a moment..) of temp's next node
    }

    temp->next = newNode; // Finally, making our newNode as next of temp, as in the bubble visualization and our node being the bubble itself
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printList(head); // 10 20 30 40

    insertAtPosition(&head, 25, 3);
    printList(head); // 10 20 25 30 40

    insertAtPosition(&head, 5, 1);
    printList(head); // 5 10 20 25 30 40

    return 0;
}
