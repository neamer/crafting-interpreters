#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * CHALLENGE
 * Do the same thing for C. To get some practice with pointers,
 * define a doubly linked list of heap-allocated strings.
 * Write functions to insert, find, and delete items from it.
 * Test them.
 */

struct Node {
    struct Node* prev;
    struct Node* next;
    char* data;
};

struct LinkedList {
    struct Node* head;
    int len;
};

void insert(struct LinkedList* list, char* item) {

    struct Node* node = malloc(sizeof(struct Node));
    node->data = item;

    if(list->head == NULL) {
        node->prev = NULL;
        node->next = NULL;
        list->head = node;
    } else {
        struct Node* current = list->head;

        while(current->next != NULL) {
            node->prev = current;
            current = current->next;
        }

        current->next = node;
    }
}

int eq(char* item1, char* item2) {
    int item1_len = strlen(item1);
    int item2_len = strlen(item2);

    if(item1_len != item2_len) {
        return 0;
    } else {
        for (int i = 0; i < item1_len; i++) {
            if(item1[i] != item2[i]) {
                return 0;
            }
        }
    }

    return 1;
}

struct Node* find(struct LinkedList* list, char* item) {
    struct Node* node = list->head;

    while (node != NULL) {
        if (eq(node->data, item)) {
            return node;
        }
        node = node ->next;
    }

    return NULL;
}

int delete(struct LinkedList* list, char* item) {
    struct Node* prev = NULL;
    struct Node* node = list->head;

    int found = 0;
    while (node != NULL && found == 0) {
        if (eq(node->data, item)) {
            found = 1;
        } else {
            prev = node;
            node = node->next;
        }
    }

    if(found == 1) {
        if(prev == NULL) {
            list->head = NULL;
        } else {
            prev->next = node->next;
        }
        free(node);
        return 1;
    } else {
        return 0;
    }
}


void print_list(struct LinkedList* list) {
    struct Node* node = list->head;

    printf("LINKED LIST =====\n");
    printf("Length: %d\n", list->len);

    printf("-----------------\n");
    while (node != NULL) {
        printf("%s\n", node->data);
        node = node->next;
    }
    printf("=================\n\n");
}

void clear(struct LinkedList* list) {
    struct Node* node = list->head;
    struct Node* next = NULL;

    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }
}

int main(int len, char** args) {

    struct LinkedList* list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->len = 0;

    insert(list, "first item");
    insert(list, "second item");
    insert(list, "third item");

    print_list(list);

    struct Node* found = find(list, "second item");

    printf("Found: %s\n", found->data);

    found = find(list, "fourth item");

    if(found == NULL) {
        printf("Fourth item not found\n");
    }

    delete(list, "first item");
    delete(list, "second item");
    delete(list, "third item");

    insert(list, "after wipe");

    print_list(list);

    insert(list, "first item");
    insert(list, "second item");
    insert(list, "third item");

    clear(list);
    free(list);

    return 0;
}
