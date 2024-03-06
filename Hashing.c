#include <stdio.h>

#define TABLE_SIZE 10

int hash_table[TABLE_SIZE] = {0};

void insert(int key) {
    int i = 0;
    int hkey = key % TABLE_SIZE;
    int index = hkey;

    while (hash_table[index] != 0) {
        i++;
        index = (hkey + i) % TABLE_SIZE;
        if (i == TABLE_SIZE) {
            printf("Hash table is full!\n");
            return;
        }
    }

    hash_table[index] = key;
}

void search(int key) {
    int i = 0;
    int hkey = key % TABLE_SIZE;
    int index = hkey;

    while (hash_table[index] != key) {
        i++;
        index = (hkey + i) % TABLE_SIZE;
        if (i == TABLE_SIZE) {
            printf("Element not found in hash table!\n");
            return;
        }
    }

    printf("Element found at index %d\n", index);
}

int main() {
    int choice;
    int key;
    while(1){
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter Key: ");
                    scanf("%d", &key);
                    insert(key);
                    break;
            case 2: printf("Enter Key: ");
                    scanf("%d", &key);
                    search(key);
                    break;
            default: return 0;
        }
    }
    return 0;
}
