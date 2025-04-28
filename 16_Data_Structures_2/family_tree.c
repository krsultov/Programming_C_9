#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char firstname[50];
    struct Node *father;
    struct Node *mother;
    struct Node *marriedto;
} Node;

Node* init_member(const char *firstname, Node *father, Node *mother, Node *marriedto) {
    Node *new_member = malloc(sizeof(Node));
    if (new_member == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(new_member->firstname, firstname);
    new_member->father = father;
    new_member->mother = mother;
    new_member->marriedto = marriedto;
    return new_member;
}

void print_member(Node *member) {
    if (member == NULL) {
        return;
    }
    printf("Name: %s\n", member->firstname);
    if (member->father) {
        printf("Father: %s\n", member->father->firstname);
    } else {
        printf("Father: Unknown\n");
    }
    if (member->mother) {
        printf("Mother: %s\n", member->mother->firstname);
    } else {
        printf("Mother: Unknown\n");
    }
    if (member->marriedto) {
        printf("Married to: %s\n", member->marriedto->firstname);
    } else {
        printf("Married to: Not married\n");
    }
    printf("\n");
}

int main() {
    Node *grandmother = init_member("Margaret", NULL, NULL, NULL);
    Node *grandfather = init_member("William", NULL, NULL, NULL);
    Node *mother = init_member("Elizabeth", grandfather, grandmother, NULL);
    Node *grandfather_1 = init_member("Charles", NULL, NULL, NULL);
    Node *grandmother_1 = init_member("Catherine", NULL, NULL, NULL);
    Node *father = init_member("James", grandfather_1, grandmother_1, NULL);
    Node *child = init_member("Henry", father, mother, NULL);

    father->marriedto = mother;
    mother->marriedto = father;
    grandfather->marriedto = grandmother;
    grandmother->marriedto = grandfather;
    grandfather_1->marriedto = grandmother_1;
    grandmother_1->marriedto = grandfather_1;

    print_member(grandfather);
    print_member(grandmother);
    print_member(grandfather_1);
    print_member(grandmother_1);
    print_member(father);
    print_member(mother);
    print_member(child);

    free(grandfather);
    free(grandmother);
    free(grandfather_1);
    free(grandmother_1);
    free(father);
    free(mother);
    free(child);

    return 0;
}