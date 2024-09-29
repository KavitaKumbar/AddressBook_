#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>
#include "validateContact.h"
#include "editContact.h"
#include "deleteContact.h"
#include "searchContact.h"

void listContacts(AddressBook *addressBook)
{
	// displaying all contacts present in the addressbook
	printf("\n-----------------------------------------------------------------------------------------\n");
	printf("SL.NO   Contact Name\t\t\tMobile Number\t\t\tE-mail Id\n");
	printf("-----------------------------------------------------------------------------------------");
	for (int i = 0; i < addressBook->contactCount; i++)
	{
		printf("\n%d.\t%s\t\t\t%s\t\t\t%s", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
	}
	printf("\n---------------------------------------------------------------------------------------\n");
}

void initialize(AddressBook *addressBook)
{
	// populateAddressBook(addressBook);

	// Load contacts from file during initialization (After files)
	loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
	saveContactsToFile(addressBook); // Save contacts to file
	exit(EXIT_SUCCESS);				 // Exit the program
}

void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
	Contact tempContact;

	printf("Name : ");
	scanf(" %[^\n]", tempContact.name);

	printf("Contact Number : ");
	scanf(" %[^\n]", tempContact.phone);

	printf("Email Id : ");
	scanf(" %[^\n]", tempContact.email);

	int flag = 0;
	if (validateName(addressBook, tempContact.name))
	{
		if (validatePhone(addressBook, tempContact.phone))
		{
			if (validateEmail(addressBook, tempContact.email))
			{
				flag = 1;
				addressBook->contacts[addressBook->contactCount++] = tempContact;
				printf("\033[1;32m");
				printf("Contact added successfully.\n");
				printf("\033[0m");
			}
		}
	}
	if (flag == 0)
	{
		printf("\033[1;31m");
		printf("Contact addition failed\n");
		printf("Please enter a valid contact\n");
		printf("\033[0m");
		createContact(addressBook);
	}
}

void searchContact(AddressBook *addressBook)
{
	/* Define the logic for search */
	int choise;
	do
	{
		printf("\033[3;32m");
		printf("choose an option to search  contact:\n");
		printf("1:Name\n2:Phone\n3:Email\n 4:Exit\n");
		printf("\033[0m");

		scanf(" %d", &choise);

		switch (choise)
		{
		case 1:
		{
			char name[50];
			printf("Enter name:");
			scanf(" %[^\n]", name);

			searchName(name, addressBook);
		}
		break;

		case 2:
		{
			char phone[20];
			printf("Enter Mobile number: \n");
			scanf(" %[^\n]", phone);

			searchPhone(phone, addressBook);
		}
		break;

		case 3:
		{
			char email[50];
			printf("Enter Email Id: \n");
			scanf(" %[^\n]", email);

			searchEmail(email, addressBook);
		}
		break;
		case 4:
			printf("\033[1;33m");
			printf("Exit......\n");
			printf("\033[0m");
			break;

		default:
			printf("\033[1;33m");
			printf("Error : Invalid Choise\n");
			printf("\033[0m");
		}
	} while (choise != 4);
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
	int choise;
	do
	{
		printf("\033[3;32m");
		printf("choose an option to edit contact:\n");
		printf("1:Name\n2:Email\n 3:Exit\n");
		printf("\033[0m");
		scanf(" %d", &choise);
		switch (choise)
		{
		case 1:
		{
			char name[50];
			printf("Enter name:");
			scanf(" %[^\n]", name);
			int i = 0;
			int flag = 0;
			AddressBook tempAdd;
			tempAdd.contactCount = 0;
			while (i < addressBook->contactCount)
			{
				if (strstr(addressBook->contacts[i].name, name))
				{
					flag = 1;
					strcpy(tempAdd.contacts[tempAdd.contactCount].name, addressBook->contacts[i].name);
					strcpy(tempAdd.contacts[tempAdd.contactCount].phone, addressBook->contacts[i].phone);
					strcpy(tempAdd.contacts[tempAdd.contactCount].email, addressBook->contacts[i].email);
					tempAdd.contactCount++;
				}
				i++;
			}
			if (flag == 1)
			{
				listContacts(&tempAdd);
				int index;
				printf("Enter the serial number which you want to edit: ");
				scanf(" %d", &index);
				if (index > 0 && index <= tempAdd.contactCount)
				{
					editname(tempAdd.contacts[index - 1], addressBook);
				}
				else
				{
					printf("\033[1;32m");
					printf("Contact not found at the index:\n");
					printf("\033[0m");
				}
			}
			else
			{
				printf("flag 0\n");
				printf("\033[1;32m");
				printf("Contact Not Found\n");
				printf("Please enter a valid details\n");
				printf("\033[0m");
			}
		}
		break;

		case 2:
		{
			char email[50];
			printf("Enter Email ID:");
			scanf(" %[^\n]", email);

			int i = 0;
			int flag = 0;
			AddressBook tempAdd;
			tempAdd.contactCount = 0;
			while (i < addressBook->contactCount)
			{
				if (strstr(addressBook->contacts[i].email, email))
				{
					flag = 1;
					strcpy(tempAdd.contacts[tempAdd.contactCount].name, addressBook->contacts[i].name);
					strcpy(tempAdd.contacts[tempAdd.contactCount].phone, addressBook->contacts[i].phone);
					strcpy(tempAdd.contacts[tempAdd.contactCount].email, addressBook->contacts[i].email);
					tempAdd.contactCount++;
				}
				i++;
			}
			if (flag == 1)
			{
				listContacts(&tempAdd);
				int index;
				printf("Enter the serial number which you want to edit: ");
				scanf(" %d", &index);
				if (index > 0 && index <= tempAdd.contactCount)
				{
					editemail(tempAdd.contacts[index - 1], addressBook);
				}
				else
				{
					printf("\033[1;32m");
					printf("Contact not found at the index:\n");
					printf("\033[0m");
				}
			}
			else
			{
				printf("\033[1;32m");
				printf("Contact Not Found\n");
				printf("Please enter a valid details\n");
				printf("\033[0m");
			}
		}
		break;

		case 3:
			printf("\033[1;33m");
			printf("Exit......\n");
			printf("\033[0m");
			break;

		default:
			printf("\033[1;33m");
			printf("Error : Invalid Choise\n");
			printf("\033[0m");
		}
	} while (choise != 3);
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for Delete contact */
	int choice;
	do
	{
		printf("\033[3;32m");
		printf("Choose option to delete contact:");
		printf("\n1:Name\n2:Phone Number\n3:Email\n4:exit\n");
		printf("\033[0m");
		scanf(" %d", &choice);
		switch (choice)
		{
		case 1:
		{
			char name[50];
			printf("Enter the name of the contact you want to delete: ");
			scanf(" %[^\n]", name);
			int i = 0;
			int flag = 0;
			AddressBook tempAdd;
			tempAdd.contactCount = 0;
			while (i < addressBook->contactCount)
			{
				if (strstr(addressBook->contacts[i].name,name))
				{
					flag = 1;
					strcpy(tempAdd.contacts[tempAdd.contactCount].name, addressBook->contacts[i].name);
					strcpy(tempAdd.contacts[tempAdd.contactCount].phone, addressBook->contacts[i].phone);
					strcpy(tempAdd.contacts[tempAdd.contactCount].email, addressBook->contacts[i].email);
					tempAdd.contactCount++;
				}
				i++;
			}
			if (flag == 1)
			{
				listContacts(&tempAdd);
				int index;
				printf("Enter the serial number which you want to edit: ");
				scanf(" %d", &index);
				if (index > 0 && index <= tempAdd.contactCount)
				{
					deletename(tempAdd.contacts[index - 1], addressBook);
				}
				else
				{
					printf("\033[1;31m");
					printf("Contact not found at the index:\n");
					printf("\033[0m");
				}
			}
			else
			{
				printf("\033[1;31m");
				printf("Contact Not Found\n");
				printf("Please enter a valid details\n");
				printf("\033[0m");
			}
		}
		break;

		case 2:
		{
			char phone[50];
			printf("Enter the phone number you want to delete: ");
			scanf(" %[^\n]",phone);
			int i = 0;
			int flag = 0;
			AddressBook tempAdd;
			tempAdd.contactCount = 0;
			while (i < addressBook->contactCount)
			{
				if (strstr(addressBook->contacts[i].phone,phone))
				{
					flag = 1;
					strcpy(tempAdd.contacts[tempAdd.contactCount].name, addressBook->contacts[i].name);
					strcpy(tempAdd.contacts[tempAdd.contactCount].phone, addressBook->contacts[i].phone);
					strcpy(tempAdd.contacts[tempAdd.contactCount].email, addressBook->contacts[i].email);
					tempAdd.contactCount++;
				}
				i++;
			}
			if (flag == 1)
			{
				listContacts(&tempAdd);
				int index;
				printf("Enter the serial number which you want to edit: ");
				scanf(" %d", &index);
				if (index > 0 && index <= tempAdd.contactCount)
				{
					deletename(tempAdd.contacts[index - 1], addressBook);
				}
				else
				{
					printf("\033[1;31m");
					printf("Contact not found at the index:\n");
					printf("\033[0m");
				}
			}
			else
			{
				printf("\033[1;31m");
				printf("Contact Not Found\n");
				printf("Please enter a valid details\n");
				printf("\033[0m");
			}
		}
		break;


		case 3:
		{
			char email[50];
			printf("Enter the email of the contact you want to delete: ");
			scanf(" %[^\n]", email);
			int i = 0;
			int flag = 0;
			AddressBook tempAdd;
			tempAdd.contactCount = 0;
			while (i < addressBook->contactCount)
			{
				if (strstr(addressBook->contacts[i].email,email))
				{
					flag = 1;
					strcpy(tempAdd.contacts[tempAdd.contactCount].name, addressBook->contacts[i].name);
					strcpy(tempAdd.contacts[tempAdd.contactCount].phone, addressBook->contacts[i].phone);
					strcpy(tempAdd.contacts[tempAdd.contactCount].email, addressBook->contacts[i].email);
					tempAdd.contactCount++;
				}
				i++;
			}
			if (flag == 1)
			{
				listContacts(&tempAdd);
				int index;
				printf("Enter the serial number which you want to edit: ");
				scanf(" %d", &index);
				if (index > 0 && index <= tempAdd.contactCount)
				{
					deletename(tempAdd.contacts[index - 1], addressBook);
				}
				else
				{
					printf("\033[1;31m");
					printf("Contact not found at the index:\n");
					printf("\033[0m");
				}
			}
			else
			{
				printf("\033[1;31m");
				printf("Contact Not Found\n");
				printf("Please enter a valid details\n");
				printf("\033[0m");
			}
		}
		break;

		case 4:
			printf("\033[1;33m");
			printf("Exit......\n");
			printf("\033[0m");
			break;

		default:
			printf("\033[1;31m");
			printf("Error : Invalid Choise\n");
			printf("\033[0m");
		}
		}
		while (choice != 4);
	}
