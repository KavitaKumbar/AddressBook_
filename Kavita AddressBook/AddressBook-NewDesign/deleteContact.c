#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"contact.h"
 void deletename( Contact temp, AddressBook *addressBook)
 {
     int i = 0;
     while(i < addressBook -> contactCount)
     {
        if(!strcmp(addressBook -> contacts[i].name,temp.name))
        {
            for(int j = i;j<addressBook -> contactCount;j++)
            {
                addressBook -> contacts[j] = addressBook -> contacts[j+1];
            }
            addressBook ->contactCount--;
            printf("\033[1;32m");
            printf("contact deleted successfully\n");
            printf("\033[0m");
            return;
        }
        i++;
     }
     printf("\033[1;32m");
     printf("Contact not found.\n");
     printf("\033[0m");
 }

 void deletephone(Contact temp, AddressBook *addressBook)
 {
     char phone[15];
     printf("Enter the phone number of the contact you want to delete: ");
     scanf(" %[^\n]",phone);
     int i = 0;
     while(i < addressBook -> contactCount)
     {
        if(!strcmp(addressBook -> contacts[i].phone,phone))
        {
            for(int j = i;j<addressBook -> contactCount;j++)
            {
                addressBook -> contacts[j] = addressBook -> contacts[j+1];
            }
            printf("\033[1;32m");
            printf("contact deleted successfully\n");
            printf("\033[0m");
            return;
        }
        i++;
     }
     printf("\033[1;32m");
     printf("Contact not found.\n");
     printf("\033[0m");
 }
 void deleteemail(Contact temp, AddressBook *addressBook)
 {
     char email[100];
     printf("Enter the email address of the contact you want to delete: ");
     scanf(" %[^\n]",email);
     int i = 0;
     while(i < addressBook -> contactCount)
     {
        if(!strcmp(addressBook -> contacts[i].email,email))
        {
            for(int j = i;j<addressBook -> contactCount;j++)
            {
                addressBook -> contacts[j] = addressBook -> contacts[j+1];
            }
            printf("\033[1;32m");
            printf("contact deleted successfully\n");
            printf("\033[0m");
            return;
        }
        i++;
     }
     printf("\033[1;31m");
     printf("Contact not found.\n");
     printf("\033[0m");
 }