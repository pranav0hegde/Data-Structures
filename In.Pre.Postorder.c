#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return newnode(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data); // Added space after %d for better readability
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Added space after %d for better readability
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data); // Added space after %d for better readability
    }
}

void display(struct node* root) {
    if (root != NULL) {
        printf("IN-order traversal: ");
        inorder(root);
        printf("\n");
        printf("Pre-order traversal: ");
        preorder(root);
        printf("\n");
        printf("Post-order traversal: ");
        postorder(root);
        printf("\n");
    }
}

int main() {
    struct node* root = NULL;
    int data;
    printf("Enter the elements of the tree (-1 to stop): ");
    while (scanf("%d", &data) && data != -1) {
        root = insert(root, data);
    }
    display(root);
    return 0;
}
