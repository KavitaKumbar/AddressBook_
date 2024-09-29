#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "validateContact.h"
void editname(Contact temp, AddressBook *addressBook)
{
    int flag = 0;
    int i = 0;
    while (i < addressBook->contactCount)
    {
        if (strcmp(addressBook->contacts[i].name, temp.name) == 0)
        {
            flag = 1;
            int choice;
            do
            {
                printf("\033[1m");
                printf("choose menu to edit\n1:name\n2:phone\n3:email\n4:exit\n");
                printf("\033[0m");
                scanf(" %d", &choice);
                switch (choice)
                {
                case 1:
                {
                    char name[50];
                    printf("Enter new name: ");
                    scanf(" %[^\n]", name);
                    if (validateName(addressBook, name))
                    {
                        strcpy(addressBook->contacts[i].name, name);
                    }
                }
                break;
                case 2:
                {
                    char phone[20];
                    printf("Enter new phone: ");
                    scanf(" %[^\n]", phone);
                    if (validatePhone(addressBook, phone))
                    {
                        strcpy(addressBook->contacts[i].phone, phone);
                    }
                }
                break;
                case 3:
                {
                    char email[20];
                    printf("Enter new email: ");
                    scanf(" %[^\n]", email);
                    if (validateEmail(addressBook, email))
                    {
                        strcpy(addressBook->contacts[i].email, email);
                    }
                }
                break;
                case 4:
                    printf("\033[1;33m");
                    printf("Exit......\n");
                    printf("\033[0m");
                    break;

                default:
                    printf("\033[1;32m");
                    printf("Invalid choice.\nEnter valid option.\n");
                    printf("\033[0m");
                }

            } while (choice != 4);
        }
        i++;
    }
    if (flag == 1)
    {
        printf("\033[1;32m");
        printf("Contact Edited Successfully!!!!\n");
        printf("\033[0m");
    }
    else
    {
        printf("\033[1;31m");
        printf("Contact Edition Failed!!!!!\n");
        printf("\033[0m");
    }
}

void editemail(Contact temp, AddressBook *addressBook)
{
    int flag = 0;
    int i = 0;
    while (i < addressBook->contactCount)
    {
        if (strcmp(addressBook->contacts[i].email, temp.email) == 0)
        {
            flag = 1;
            int choice;
            do
            {
                printf("\033[1m");
                printf("choose menu to edit\n1:name\n2:phone\n3:email\n4:exit\n");
                printf("\033[0m");
                scanf(" %d", &choice);
                switch (choice)
                {
                case 1:
                {
                    char name[50];
                    printf("Enter new name: ");
                    scanf(" %[^\n]", name);
                    if (validateName(addressBook, name))
                    {
                        strcpy(addressBook->contacts[i].name, name);
                    }
                }
                break;
                case 2:
                {
                    char phone[20];
                    printf("Enter new phone: ");
                    scanf(" %[^\n]", phone);
                    if (validatePhone(addressBook, phone))
                    {
                        strcpy(addressBook->contacts[i].phone, phone);
                    }
                }
                break;
                case 3:
                {
                    char email[20];
                    printf("Enter new email: ");
                    scanf(" %[^\n]", email);
                    if (validateEmail(addressBook, email))
                    {
                        strcpy(addressBook->contacts[i].email, email);
                    }
                }
                break;
                case 4:
                    printf("\033[1;33m");
                    printf("Exit......\n");
                    printf("\033[0m");
                    break;

                default:
                    printf("\033[1;32m");
                    printf("Invalid choice\n");
                    printf("\033[0m");
                }

            } while (choice != 4);
        }
        i++;
    }
    if (flag == 1)
    {
        printf("\033[1;32m");
        printf("Contact Edited Successfully!!!!\n");
        printf("\033[0m");
    }
    else
    {
        printf("\033[1;31m");
        printf("Contact Edition Failed!!!!!\n");
        printf("\033[0m");
    }
}
