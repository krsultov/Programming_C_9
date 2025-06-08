#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

void addBook(LinkedList *book_list) {
    Book book;
    printf("Enter book name: ");
    scanf("%127s", book.name);
    printf("Enter book author: ");
    scanf("%127s", book.author);
    printf("Enter book genre: ");
    scanf("%127s", book.genre);
    printf("Enter year of publication: ");
    scanf("%d", &book.year_of_publication);
    printf("Enter book ISBN: ");
    scanf("%127s", book.isbn);
    pushBack(book_list, book);
}

void displayBooks(LinkedList *book_list) {
    Node *current = book_list->head;
    while (current) {
        Book *book = &current->value;
        printf("Name: %s, Author: %s, Genre: %s, Year: %d, ISBN: %s\n",
               book->name, book->author, book->genre, book->year_of_publication, book->isbn);
        current = current->next;
    }
}

void deleteBookByISBN(LinkedList *book_list, const char *isbn) {
    Node *current = book_list->head;
    Node *prev = NULL;
    while (current) {
        Book *book = &current->value;
        if (strcmp(book->isbn, isbn) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                book_list->head = current->next;
            }
            free(current);
            book_list->size--;
            printf("Book with ISBN %s deleted.\n", isbn);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Book with ISBN %s not found.\n", isbn);
}

void saveToFile(LinkedList *book_list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    Node *current = book_list->head;
    while (current) {
        Book *book = &current->value;
        fprintf(file, "%s %s %s %d %s\n",
                book->name, book->author, book->genre,
                book->year_of_publication, book->isbn);
        current = current->next;
    }
    fclose(file);
    printf("Books saved to file.\n");
}

void loadFromFile(LinkedList *book_list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    Book book;
    while (fscanf(file, "%127s %127s %127s %d %127s",
                  book.name, book.author, book.genre,
                  &book.year_of_publication, book.isbn) == 5) {
        pushBack(book_list, book);
    }
    fclose(file);
    printf("Books loaded from file.\n");
}

int main(void) {
    LinkedList book_list = init();
    loadFromFile(&book_list, "library.txt");

    int choice;
    char isbn[MAX_NAME_LEN];

    while (1) {
        printf("1. Add Book\n2. Display Books\n3. Delete Book by ISBN\n4. Save to File\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&book_list);
                break;
            case 2:
                displayBooks(&book_list);
                break;
            case 3:
                printf("Enter ISBN to delete: ");
                scanf("%127s", isbn);
                deleteBookByISBN(&book_list, isbn);
                break;
            case 4:
                saveToFile(&book_list, "library.txt");
                break;
            case 5:
                release(&book_list);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
