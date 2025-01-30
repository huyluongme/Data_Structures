#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

// Definition of a Node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Creating a new Node
struct Node* newNode(int data) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = NULL;
    return tmp; 
}

// Traversing and printing the elements of the linked list 
void traverseLinkedList(struct Node* head) {
    struct Node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Searching for a value in the linked list
bool searchLinkedList(struct Node* head, int target) {
    while(head != NULL) {
        if(head->data == target) return true;
        head = head->next;
    }
    return false;
}

// Finding the length of the linked list
int findLength(struct Node* head) {
    int length = 0;
    struct Node* curr = head;
    while(curr != NULL) {
        length++;
        curr = curr->next;
    }
    return length;
}

// Inserting a new Node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = head;
    head = new_node;
    return head;
}

// Inserting a new Node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* new_node = newNode(value);
    
    if(head == NULL) return new_node;
    
    struct Node* curr = head;
    while(curr->next != NULL) curr = curr->next;
    curr->next = new_node;
    return head;
} 

// Inserting a new Node at a specificed position
struct Node* insertPos(struct Node* head, int pos, int value) {
    if(pos < 1) {
        printf("Invalid position!\n");
        return head;
    }

    if(pos == 1) return insertAtBeginning(head, value);

    struct Node* prev = head;
    int cnt = 1;
    while(cnt < pos - 1 && prev != NULL) {
        prev = prev->next;
        cnt++;
    }

    if(prev == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    struct Node* tmp = newNode(value);
    tmp->next = prev->next;
    prev->next = tmp;
    return head;
}

// Removing the first node of the linked list
struct Node* removeFirstNode(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* tmp = head;
    head = head->next;

    free(tmp);
    return head;
}

// Removing the last node of the linked list
struct Node* removeLastNode(struct Node* head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* second_last = head;
    while(second_last->next->next != NULL) second_last = second_last->next;

    free(second_last->next);

    second_last->next = NULL;
    
    return head;
}

// Deleting a node at a specific position
struct Node* deleteAtPos(struct Node* head, int position) {
    if(head == NULL || position < 1) return head;

    if(position == 1) return removeFirstNode(head);

    struct Node* curr = head;
    for (int i = 1; i < position - 1 && curr != NULL; i++) {
        curr = curr->next;
    }
    
    if(curr == NULL || curr->next == NULL) return head;

    struct Node* tmp = curr->next;

    curr->next = curr->next->next;

    free(tmp);
    return head;
}

int main() {
    struct Node* head = newNode(1);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    head = insertPos(head, 3, 10);
    traverseLinkedList(head);

    printf("%d\n", searchLinkedList(head, 2));
    printf("Length of linked list: %d\n", findLength(head));

    head = removeFirstNode(head);
    head = removeLastNode(head);
    head = deleteAtPos(head, 3);
    traverseLinkedList(head);
    return 0;
}