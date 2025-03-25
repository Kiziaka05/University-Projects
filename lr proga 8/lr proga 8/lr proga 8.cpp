#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct Contact {
    char surname[50];
    char phoneNumber[20];
};
void replaceContact(struct Contact contacts[], int size, const char* targetSurname) {
    int i;
    for (i = 0; i < size; ++i) {
        if (strcmp(contacts[i].surname, targetSurname) == 0) {
            printf("Enter new surname for %s: ", targetSurname);
            scanf_s("%s", contacts[i].surname, sizeof(contacts[i].surname));

            printf("Enter new phone number for %s: ", contacts[i].surname);
            scanf_s("%s", contacts[i].phoneNumber, sizeof(contacts[i].phoneNumber));

            printf("Record replaced successfully.\n");
            return;
        }
    }
    printf("Record with surname %s not found.\n", targetSurname);
}
void sortContacts(struct Contact contacts[], int size) {
    int i, j;
    struct Contact temp;
    for (i = 0; i < size - 1; ++i) {
        for (j = 0; j < size - i - 1; ++j) {
            if (strcmp(contacts[j].surname, contacts[j + 1].surname) > 0) {

                temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the number of contacts: ");
    scanf_s("%d", &n);
    if (n <= 0 || n > MAX_SIZE) {
        printf("Incorrect number of contacts.\n");
        return 1;
    }
    struct Contact* contacts = (struct Contact*)malloc(n * sizeof(struct Contact));
    if (contacts == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("Enter surname for contact %d: ", i + 1);
        scanf_s("%s", contacts[i].surname, sizeof(contacts[i].surname));
        printf("м %d: ", i + 1);
        scanf_s("%s", contacts[i].phoneNumber, sizeof(contacts[i].phoneNumber));
    }
    printf("\nInitial array of contacts:\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\t%s\n", contacts[i].surname, contacts[i].phoneNumber);
    }
    char targetSurname[50];
    printf("\nEnter surname for change: ");
    scanf_s("%s", targetSurname, sizeof(targetSurname));
    replaceContact(contacts, n, targetSurname);
    printf("\nArray of contacts after change:\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\t%s\n", contacts[i].surname, contacts[i].phoneNumber);
    }
    sortContacts(contacts, n);
    printf("\nArray of contacts after sorting by surname:\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\t%s\n", contacts[i].surname, contacts[i].phoneNumber);
    }
  
    free(contacts);
    return 0;
}
