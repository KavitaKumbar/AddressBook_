#ifndef  VALIDATECONTACT_H
#define  VALIDATECONTACT_H
#include "contact.h"

int strisdigit(const char * str);
void displayContact(AddressBook * addressBook,int index);
int validateName(AddressBook *addressBook, const char *name);
int validatePhone(AddressBook *addressBook, const char *phone);
int validateEmail(AddressBook *addressBook, const char *email);

#endif