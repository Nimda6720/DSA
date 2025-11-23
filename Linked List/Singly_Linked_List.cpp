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

void deleteFirstOccurrence(Node** head, int value_to_delete) {

    //1. Check if the list is empty
    if (*head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = *head;//Think of temp as a detective going through the list, while head stays pointing to the start.
    Node* prev = NULL;

    //2. If the head node itself holds the value
    if (temp != NULL && temp->value == value_to_delete) {
        *head = temp->next; //move head
        delete temp; //free old head
        return;
    }

    //3. Search for the value to delete
    //   Keep track of the previous node
    while (temp != NULL && temp->value != value_to_delete) {
        prev = temp;
        temp = temp->next;
        //this allows to move one step forward in the list like hydra movement
    }

    //4. If value was not found
    if (temp == NULL) {
        cout << "Value not found in the list\n";
        return;
    }

    //5. Unlink the node from the linked list
    prev->next = temp->next;

    //6. Delete the node
    delete temp;
}

void deleteAtPosition(Node** head, int position) {
    //1. Check if list is empty
    if (*head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = *head; // detective starts at head
    //2. If head needs to be removed
    if (position == 0) {
        *head = temp->next; // move head to next node
        delete temp;        // free old head
        return;
    }

    //3. Find the previous node of the node to be deleted AKA main target
    Node* prev = NULL;
    int count = 0;
    while (temp != NULL && count < position) {
        prev = temp;     
        temp = temp->next; 
        // move forward like hydra movement
        count++;
    }

    //4. If position is more than number of nodes
    if (temp == NULL) {
        cout << "Position out of range\n";
        return;
    }

    //5. Unlink the node from linked list
    prev->next = temp->next;

    //6. Delete the node
    delete temp;
}

int countNodes(Node* head) {
    int count = 0;              // 1. Start counting from 0
    Node* current = head;       // 2. Detective starts at the head, exploring each node

    while (current != NULL) {   // 3. Keep moving forward until we reach the end
        count++;                
        current = current->next; // 4. Moved like Hydra to the next node
    }

    return count;               // 5. Return total nodes counted
}

bool searchValue(Node* head, int key) {
    Node* current = head; // Detective starts at the head, searching for the key
 
    while (current != NULL) // Traverse the linked list
    {  
        if (current->value == key) { 
            return true;
        }
        current = current->next; // Move forward like Hydra
    }
    return false; // Key not found after reaching end of list
}

void reverseList(Node** head) {
    Node* prev = NULL;       // 1. Previous node starts as NULL (detective's past memory)
    Node* current = *head;   // 2. Current node starts at head (detective now)
    Node* next = NULL;       // 3. To preserve the address of the next nod. So that it is not lost.

    while (current != NULL) {   
        next = current->next;   // Preserving next node address (detective notes down next location)
        current->next = prev;   // Reverse the pointer. Now, current points to previous pointer cz we are reversing the list
        prev = current;         // Move prev forward (detective steps back)
        current = next;         // Move current forward (detective moves to next node)
    }

    *head = prev;   // 5. Move head to the last node (new starting point)
    
    //Read the second reply of chatgpt provided in Notion
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

    deleteFirstOccurrence(&head, 2);
    deleteAtPosition(&head, 3);

    int totalNodes = countNodes(head);
    
    reverseList(&head);
    
    printList(head);
    cout << endl;
    cout << "Total nodes in the list: " << totalNodes << endl;

    if (searchValue(head, -2))//Used Boolean
    {
        cout << "-2 is found in the list" << endl;
    } else {
        cout << "-2 is not found in the list" << endl;
    }
    return 0;
}
