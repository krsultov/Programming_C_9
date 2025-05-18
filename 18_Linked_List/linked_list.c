#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

static void assertIndexInBounds(LinkedList* list, uint index) {
    if (index >= list->size) {
        printf("Index out of bounds!\n");
        exit(EXIT_FAILURE);
    }
}

static Node* createNode(ListType value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->next = NULL;
    return node;
}

static Node* getNode(LinkedList* list, uint index) {
    assertIndexInBounds(list, index);
    Node* current = list->head;
    for (uint i = 0; i < index; ++i) current = current->next;
    return current;
}


LinkedList init() {
    LinkedList list = {.head = NULL, .size = 0};
    return list;
}

void pushFront(LinkedList* list, ListType value) {
    Node* node = createNode(value);
    node->next = list->head;
    list->head = node;
    ++list->size;
}

void pushBack(LinkedList* list, ListType value) {
    if (list->size == 0) {
        pushFront(list, value);
        return;
    }
    Node* last = getNode(list, list->size - 1);
    last->next = createNode(value);
    ++list->size;
}

void push(LinkedList* list, uint index, ListType value) {
    if (index == 0) {
        pushFront(list, value);
    }
    else if (index >= list->size) {
        pushBack(list, value);
    }
    else {
        Node* prev = getNode(list, index - 1);
        Node* node = createNode(value);
        node->next = prev->next;
        prev->next = node;
        ++list->size;
    }
}


ListType popFront(LinkedList* list) {
    assertIndexInBounds(list, 0);
    Node* selected = list->head;
    ListType val = selected->value;
    list->head = selected->next;
    free(selected);
    --list->size;
    return val;
}

ListType popBack(LinkedList* list) {
    assertIndexInBounds(list, 0);
    if (list->size == 1) return popFront(list);

    Node* prev = getNode(list, list->size - 2);
    Node* selected = prev->next;
    ListType val = selected->value;
    prev->next = NULL;
    free(selected);
    --list->size;
    return val;
}

ListType pop(LinkedList* list, uint index) {
    if (index == 0) return popFront(list);
    if (index >= list->size - 1) return popBack(list);

    Node* prev = getNode(list, index - 1);
    Node* selected = prev->next;
    ListType val = selected->value;
    prev->next = selected->next;
    free(selected);
    --list->size;
    return val;
}

ListType get(LinkedList* list, uint index) {
    return getNode(list, index)->value;
}

void set(LinkedList* list, uint index, ListType value) {
    getNode(list, index)->value = value;
}

void release(LinkedList* list) {
    while (list->size) popFront(list);
}
