#include <stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;


typedef struct sList {
    struct node* head;
} sList_t;

node_t* makeNode(int data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

sList_t* makeList() {
    sList_t* newList = (sList_t*)malloc(sizeof(sList_t));
    newList->head = NULL;
    return newList;
}

void print(sList_t* l) {
    node_t *temp;
    temp = l->head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int search(sList_t* l, int data) {
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

void insert(sList_t* l, int data, int pos) {
    printf("Original linked list: ");
    print(l);
    node_t* dummy = l->head;
    for (int i = 1; i < pos-1; i++) {
        dummy = dummy->next;
    }
    node_t* temp = dummy->next;
    dummy->next = makeNode(data);
    dummy->next->next = temp;
    printf("After insertion: ");
    print(l);
    printf("\n");
}

void insertFirst(sList_t* l, int data) {
    printf("Insert first\n");
    printf("--------------------\n");
    printf("Original linked list: ");
    print(l);
    node_t* first = makeNode(data);
    first->next = l->head;
    l->head = first;
    printf("After insertion: ");
    print(l);
    printf("\n");
}

void insertLast(sList_t* l, int data) {
    printf("Insert last\n");
    printf("--------------------\n");
    printf("Original linked list: ");
    print(l);
    node_t* temp = l->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = makeNode(data);
    printf("After insertion: ");
    print(l);
    printf("\n");
}

void deleteMid(sList_t* l) {
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
    printf("After deletion: ");
    print(l);
    printf("\n");
}

void deleteFirst(sList_t* l) {
    printf("Delete first\n");
    printf("--------------------\n");
    printf("Original linked list: ");
    print(l);
    node_t* dummy = l->head;
    dummy = dummy->next;
    l->head = dummy;
    printf("After deletion: ");
    print(l);
    printf("\n");
}

void deleteLast(sList_t* l) {
    printf("Delete last\n");
    printf("--------------------\n");
    printf("Original linked list: ");
    print(l);
    node_t* dummy = l->head;
    while (dummy->next->next != NULL) {
        dummy = dummy->next;
    }
    dummy->next = NULL;
    printf("After deletion: ");
    print(l);
    printf("\n");
}



int main() {
    node_t* node1 = makeNode(23);
    node_t* node2 = makeNode(52);
    node_t* node3 = makeNode(19);
    node_t* node4 = makeNode(9);
    node_t* node5= makeNode(100);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    sList_t* sl = makeList();
    sl->head = node1;
    print(sl);
    printf("\n");

    int element1;
    printf("Enter an integer for search: ");
    scanf("%d", &element1);
    int s = search(sl, element1);
    printf("Position of %d in the linked list is: %d\n ", element1, s);
    printf("\n");

    insertFirst(sl, 7);
    deleteFirst(sl);

    insertLast(sl, 7);
    deleteLast(sl);

    deleteMid(sl);

    int element2, pos;
    printf("Enter an integer for insertion: ");
    scanf("%d", &element2);
    printf("Enter its position: ");
    scanf("%d", &pos);
    insert(sl, element2, pos);

    return 0;
}
