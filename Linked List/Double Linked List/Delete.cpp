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

void deleteFromPosition(Node** head, int position) {

    // Case 1: delete from beginning
    if (position == 1) {
        Node* temp = *head;
        *head = temp->next; // Move head to next node

        if (*head != NULL) {
            (*head)->prev = NULL; // Set previous of new head to NULL
        }

        delete temp; // delete old head
        return;
    }

    // Move temp to the desired position
    Node* temp = *head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }


    // Case 2: delete from END
    if (temp->next == NULL) {
        temp->prev->next = NULL; //easier to visualize. Try to visualize by drawing on the paper. If you can't then check chatgpt responses 
        delete temp;
        return;
    }

    // Case 3: delete from MIDDLE
    temp->next->prev = temp->prev; //visualize this step by step on paper
    temp->prev->next = temp->next;

    delete temp;
}

int main() {
    Node* head = NULL;

    // Creating nodes manually since no insertion functions were added
    Node* n1 = new Node(); n1->value = 10;
    Node* n2 = new Node(); n2->value = 20;
    Node* n3 = new Node(); n3->value = 30;
    Node* n4 = new Node(); n4->value = 40;

    // Linking manually (doubly linked)
    head = n1;
    n1->next = n2; n1->prev = NULL;
    n2->next = n3; n2->prev = n1;
    n3->next = n4; n3->prev = n2;
    n4->next = NULL; n4->prev = n3;

    printList(head);   // 10 20 30 40

    deleteFromPosition(&head, 1);  // delete from beginning
    printList(head);               // 20 30 40

    deleteFromPosition(&head, 3);  // delete from end
    printList(head);               // 20 30

    deleteFromPosition(&head, 2);  // delete from middle
    printList(head);               // 20

    return 0;
}
