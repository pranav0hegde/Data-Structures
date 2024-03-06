#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("Enter data in node");
    scanf("%d", &data);
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node* *head) {
    int pos;
    printf("Enter position of new node");
    scanf("%d", &pos);
    struct Node* newNode = createNode();
    struct Node* temp = (*head);
    while(--pos){
        if(temp->next != NULL)
            temp = temp->next;
        else{
            printf("List too short");
            return;
        }
    }
    if (temp->next == NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
        (*head) = newNode;
    } else {
        temp->prev->next = newNode;
        newNode->prev = temp->prev;
        temp->prev = newNode;
        newNode->next = temp;
    }
}

void deleteNode(struct Node* *head) {
    int data;
    printf("Enter data in node to be deleted");
    scanf("%d", &data);
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Node with value %d not found", data);
}

void display(struct Node* head) {
    struct Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    struct Node* head = NULL;
    while (1) {
        printf("1. Create a list\n");
        printf("2. Insert a node\n");
        printf("3. Delete a node\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = createNode();
                break;
            case 2:
                insertNode(&head);
                break;
            case 3:
                deleteNode(&head);
                break;
            case 4:
                display(head);
                break;
            default:
                printf("Exiting the program");
                return 0;
        }
    }
}
