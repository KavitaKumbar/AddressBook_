#include <stdio.h>
#include "contact.h"


int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");

        printf("\033[1;33m");
        printf("Enter your choice: ");
        printf("\033[0m");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
           case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook);
                break;
            case 6:
                printf("\033[1;33m");
                printf("Saving and Exiting...\n");
                printf("\033[0m");
                saveContactsToFile(&addressBook);
                break;
            case 7: 
                printf("\033[1;33m");
                printf("Exit......\n");
                printf("\033[0m");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7 && choice != 6);
    
       return 0;
}
