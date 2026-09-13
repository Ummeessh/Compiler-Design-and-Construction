#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct symbtab {
    char label[10];
    int addr;
    struct symbtab *next;
};

struct symbtab *first = NULL, *last = NULL;

int search(char lab[]) {
    struct symbtab *p = first;
    while (p) {
        if (!strcmp(p->label, lab)) return 1;
        p = p->next;
    }
    return 0;
}

void show(struct symbtab *p) {
    printf("\nLabel\tAddress\n");
    printf("----------------\n");
    printf("%s\t%d\n", p->label, p->addr);
}

void insert() {
    struct symbtab *p = malloc(sizeof(*p));

    printf("Enter label: ");
    scanf("%s", p->label);

    if (search(p->label)) {
        printf("Duplicate label!\n");
        free(p);
        return;
    }

    printf("Enter address: ");
    scanf("%d", &p->addr);
    p->next = NULL;

    if (!first)
        first = p;
    else
        last->next = p;

    last = p;

    printf("\nSymbol Table after insertion:\n");
    display();
}

void display() {
    struct symbtab *p = first;

    printf("\nLabel\tAddress\n");
    printf("----------------\n");

    while (p) {
        printf("%s\t%d\n", p->label, p->addr);
        p = p->next;
    }
    printf("\n");
}

void del() {
    char lab[10];
    struct symbtab *p = first, *prev = NULL;

    printf("Enter label to delete: ");
    scanf("%s", lab);

    while (p && strcmp(p->label, lab)) {
        prev = p;
        p = p->next;
    }

    if (!p) {
        printf("Label not found!\n");
        return;
    }

    if (prev)
        prev->next = p->next;
    else
        first = p->next;

    if (p == last)
        last = prev;

    free(p);

    printf("\nAfter deletion:\n");
    display();
}

void modify() {
    char old[10], new[10];
    int choice, addr;
    struct symbtab *p = first;

    printf("\n1. Modify Label\n2. Modify Address\n3. Modify Both");
    printf("\nEnter Choice: ");
    scanf("%d", &choice);

    printf("Enter old label: ");
    scanf("%s", old);

    while (p && strcmp(p->label, old))
        p = p->next;

    if (!p) {
        printf("Label not found!\n");
        return;
    }

    if (choice == 1 || choice == 3) {
        printf("Enter new label: ");
        scanf("%s", new);

        if (search(new) && strcmp(p->label, new)) {
            printf("Duplicate label!\n");
            return;
        }

        strcpy(p->label, new);
    }

    if (choice == 2 || choice == 3) {
        printf("Enter new address: ");
        scanf("%d", &addr);
        p->addr = addr;
    }

    printf("\nSymbol Table after modification:\n");
    display();
}

int main() {
    int ch;
    char lab[10];

    do {
        printf("--- Symbol Table ---");
        printf("\n1. Insert\n2. Display\n3. Delete");
        printf("\n4. Search\n5. Modify\n6. Exit");
        printf("\n\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: del(); break;
            case 4:
                printf("Enter label: ");
                scanf("%s", lab);
                printf(search(lab) ? "Found!\n\n" : "Not found!\n\n");
                break;
            case 5: modify(); break;
            case 6: break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 6);

    return 0;
}
