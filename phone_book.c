#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone_book.h"

void look_up(PhoneBook *pBook, int iEntries)
{
    int i;
    for (i = 0; i < iEntries; i++)
    {
        printf("\n\nEntry %d", i);
        printf("\n\tName: %s", pBook[i].name);
        printf("\n\tEmails: %s", pBook[i].email);
        printf("\n\tPhone: %d", pBook[i].phone_num);
        getchar();
    }
}

void change(PhoneBook *pBook, int iEntries)
{
    char op;
    int i = 0;
    char name[40];
    printf("\n\tType the entry name:");
    fflush(stdin);
    scanf("%s", &name);

    for (i = 0; i < iEntries && strncmp(pBook[i].name, name, strlen(name)) != 0; i++);
    if (i >= iEntries)
    {
        printf("\n\tEntry not found!");
    }
    else
    {
        printf("\n\tentry %d", i);
        printf("\n\tName : %s", pBook[i].name);
        printf("\n\tEmail : %s", pBook[i].email);
        printf("\n\tPhone : %d", pBook[i].phone_num);
        printf("\n\tConfirm?(Y/y)");
        fflush(stdin);
        scanf(" %c", &op);
        if (op == 'Y' || op == 'y')
        {
            fflush(stdin);
            printf("Type the entry name: ");
            scanf("%s", &pBook[i].name);
            fflush(stdin);

            printf("Type the email: ");

            scanf("%s", &pBook[i].email);
            fflush(stdin);

            printf("Type the phone number: ");
            scanf("%d", &pBook[i].phone_num);
            fflush(stdin);
        }
    }
}

void pbook_remove(PhoneBook **pBook, int *piEntries)
{
    char op;
    int i = 0;
    char name[40];
    printf("\n\tType the entry name:");
    fflush(stdin);
    scanf("%s", &name);
    for (i = 0; i < *piEntries && strncmp((*pBook)[i].name, name, strlen(name)) != 0; i++)
        ;
    if (i >= *piEntries)
    {
        printf("\n\tEntry not found!");
    }
    else
    {
        printf("\n\tentry %d", i);
        printf("\n\tName : %s", (*pBook)[i].name);
        printf("\n\tEmail : %s", (*pBook)[i].email);
        printf("\n\tPhone : %d", (*pBook)[i].phone_num);
        printf("\n\tConfirm?(Y/y)");
        scanf(" %c", &op);
        if (op == 'Y' || op == 'y')
        {
            (*pBook)[i] = (*pBook)[(*piEntries) - 1];

            (*piEntries)--;
            /* excluo o último elemento com realoc */
            pbook_alloc(pBook, piEntries);
        }
    }
}

void pbook_alloc(PhoneBook **pBook, int *piEntries)
{
    (*pBook) = (PhoneBook *)(realloc(*pBook,
                                     (*piEntries + 1) * sizeof(PhoneBook)));
    if (*pBook == NULL)
    {
        printf("\nMemory allocation error!!! i should have written this in rust...");
        exit(1);
    }
}

void search(PhoneBook *pBook, int iEntries)
{
    char op;
    int i = 0;
    char name[40];
    printf("\n\tType the entry name:");
    fflush(stdin);
    scanf("%s", &name);

    for (i = 0; i < iEntries && strncmp(pBook[i].name, name, strlen(name)) != 0; i++)
        ;
    if (i >= iEntries)
    {
        printf("\n\tEntry not found!");
    }
    else
    {
        do
        {
            fflush(stdin);
            printf("\n\n\tRegistro %d", i);
            printf("\n\tNome : %s", pBook[i].name);
            printf("\n\tEmail : %s", pBook[i].email);
            printf("\n\tFone : %d", pBook[i].phone_num);
            printf("\n\tReturn?(Y/y)");
            scanf(" %c", &op);
            i++;
            if (i >= iEntries)
            {
                i = 0;
            }
        } while (op == 'N' || op == 'n');
    }
}

void sort(PhoneBook book[], int left, int right)
{
    register int i, j;
    char *x;
    PhoneBook t;

    i = left;
    j = right;
    x = book[(left + right) /2].name;
    do
    {
        while (strcmp(book[i].name, x) < 0 && i < right)
            i++;
        while (strcmp(book[j].name, x) > 0 && j > left)
            j--;
        if (i <= j)
        {
            t = book[i];
            book[i] = book[j];
            book[j] = t;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
        sort(book, left, i);
    if (i < right)
        sort(book, i, right);
}