#include <stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node_t;


typedef struct dList {
    struct node* head;
} dList_t;

node_t* makeNode(int data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

dList_t* makeList() {
    dList_t* newList = (dList_t*)malloc(sizeof(dList_t));
    newList->head = NULL;
    return newList;
}

void print(dList_t* l) {
    node_t *temp;
    temp = l->head;
    while (temp != NULL) {
        printf("%d<-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int search(dList_t* l, int data) {
    node_t* temp = l->head;
    int loc = 1;
    while (temp != NULL) {
        if (temp->data == data) {
            return loc;
        }
        temp = temp->next;
        loc ++;
    }
    return -1;
}

void insert(dList_t* l, int data, int pos) {
    printf("Original linked list: ");
    print(l);
    node_t* dummy = l->head;
    for (int i = 1; i < pos-1; i++) {
        dummy = dummy->next;
    }
    node_t* temp = dummy->next;
    node_t* n = makeNode(data);
    dummy->next = n;
    n->prev = dummy;
    n->next = temp;
    temp->prev = n;
    printf("After insertion: ");
    print(l);
    printf("\n");
}

void insertFirst(dList_t* l, int data) {
    printf("Insert first\n");
    printf("--------------------\n");
    printf("Original linked list: ");
    print(l);
    node_t* first = makeNode(data);
    first->next = l->head;
    l->head->prev = first;
    l->head = first;
    printf("After insertion: ");
    print(l);
    printf("\n");
}

void insertLast(dList_t* l, int data) {
    printf("Insert last\n");
    printf("--------------------\n");
    printf("Original linked list: ");
    print(l);
    node_t* temp = l->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = makeNode(data);
    makeNode(data)->prev = temp;
    printf("After insertion: ");
    print(l);
    printf("\n");
}

void deleteMid(dList_t* l) {
    printf("Delete mid\n");
    printf("--------------------\n");
    printf("Original linked list: ");
    print(l);
    int length = 0;
    node_t* dummy1 = l->head;
    while (dummy1 != NULL) {
        dummy1 = dummy1->next;
        length += 1;
    }
    length = length / 2;
    node_t* dummy2 = l->head;
    while (length > 1) {
        dummy2 = dummy2->next;
        length --;
    }
    dummy2->next = dummy2->next->next;
    dummy2->next->next->prev = dummy2->next;
    printf("After deletion: ");
    print(l);
    printf("\n");
}

void deleteFirst(dList_t* l) {
    printf("Delete first\n");
    printf("--------------------\n");
    printf("Original linked list: ");
    print(l);
    node_t* dummy = l->head;
    dummy = dummy->next;
    dummy->prev = NULL;
    l->head = dummy;
    printf("After deletion: ");
    print(l);
    printf("\n");
}

void deleteLast(dList_t* l) {
    printf("Delete last\n");
    printf("--------------------\n");
    printf("Original linked list: ");
    print(l);
    node_t* dummy = l->head;
    while (dummy->next->next != NULL) {
        dummy = dummy->next;
    }
    dummy->next->prev = NULL;
    dummy->next = NULL;
    printf("After deletion: ");
    print(l);
    printf("\n");
}

void reverse(dList_t* l) {
    printf("Original linked list: ");
    print(l);
    printf("Reversed linked list: \n");
    node_t* prev = NULL;
    node_t* curr = l->head;
    node_t* temp;
    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    while (prev != NULL) {
        printf("%d<-->", prev->data);
        prev = prev->next;
        }
        printf("NULL\n");
}

void freeNode(dList_t* l) {
    node_t *temp;
    while (l->head) {
        temp = l->head->next;
        free(l->head);
        l->head = temp;
    }
}

int main() {
    node_t* node1 = makeNode(23);
    node_t* node2 = makeNode(52);
    node_t* node3 = makeNode(19);
    node_t* node4 = makeNode(9);
    node_t* node5= makeNode(100);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    dList_t* dl = makeList();
    dl->head = node1;
    print(dl);
    printf("\n");

    int element1;
    printf("Enter an integer for search: ");
    scanf("%d", &element1);
    int s = search(dl, element1);
    printf("Position of %d in the linked list is: %d\n ", element1, s);
    printf("\n");

    insertFirst(dl, 7);
    deleteFirst(dl);

    insertLast(dl, 7);
    deleteLast(dl);

    deleteMid(dl);

    int element2, pos;
    printf("Enter an integer for insertion: ");
    scanf("%d", &element2);
    printf("Enter its position: ");
    scanf("%d", &pos);
    insert(dl, element2, pos);

    reverse(dl);

    freeNode(dl);
    free(dl);
    return 0;
}

