#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include"validateContact.h"

void searchName(char *name, AddressBook *addressBook)
{
    int i = 0;
    int flag = 0;
    AddressBook tempAdd;
    tempAdd.contactCount = 0;
    while (i < addressBook->contactCount)
    {
        if (strstr(addressBook->contacts[i].name,name))
        {
            flag = 1;
            //displayContact(addressBook, i);
            tempAdd.contacts[tempAdd.contactCount++] = addressBook ->contacts[i];
        }
        i++;
    }
    if(flag==1)
    {
        listContacts(&tempAdd);
    }
    
    if (flag == 0)
    {
        printf("\033[1;32m");
        printf("Error: Contact not found!\n");
        printf("\033[0m");
    }
}

void searchPhone(char *phone, AddressBook *addressBook)
{
    int i = 0;
    int flag = 0;

    while (i < addressBook->contactCount)
    {
        if (strstr(addressBook->contacts[i].phone,phone))
        {
            flag = 1;
            displayContact(addressBook, i);
        }
        i++;
    }
    if (flag == 0)
    {
        printf("\033[1;32m");
        printf("Error: Contact not found!\n");
        printf("\033[0m");
    }
}

void searchEmail(char *email, AddressBook *addressBook)
{
    int i = 0;
    int flag = 0;

    while (i < addressBook->contactCount)
    {
        if (strstr(addressBook->contacts[i].email,email))
        {
            flag = 1;
            displayContact(addressBook, i);
        }
        i++;
    }
    if (flag == 0)
    {
        printf("\033[1;32m");
        printf("Error: Contact not found!\n");
        printf("\033[0m");
    }
}