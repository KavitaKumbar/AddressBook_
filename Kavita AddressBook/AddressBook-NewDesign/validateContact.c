#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"contact.h"
int strisdigit(const char * str)
{
    int i = 0;int flag;
    while(str[i])
    {
      if(!isdigit(str[i]))
      {

          return 0;
      }
      i++;
    }
    return 1;
    
}

void displayContact(AddressBook * addressBook,int index)
{
    
		printf("%s\t",addressBook->contacts[index].name);
		printf("%s\t",addressBook->contacts[index].phone);
		printf("%s\n",addressBook->contacts[index].email);
		printf("***********************************************\n");

}
int validateName(AddressBook *addressBook, const char *name)
{
  int i = 0;
  while(i<addressBook->contactCount)
  {
    if(!strcmp(addressBook->contacts[i].name,name))
    {
      printf("\033[1;31m");
      printf("Error: name already exists\n");
      printf("\033[0m");
      return 0;
    }
    i++;
  }
  return 1;
}
int validatePhone(AddressBook *addressBook, const char *phone)
{
  int i = 0;
  while(i < addressBook->contactCount)
  {
    if(strisdigit(phone))
    {
      if(strlen(phone)!=10)
      {
          printf("\033[1;31m");
          printf("Error: Phone number should contains 10 digits\n");
          printf("\033[0m");
          return 0;
      }
    }
    else
    {
      printf("\033[1;31m");
      printf("Error: Phone number should contains only digits\n");
      printf("\033[0m");
      return 0;
    }
    if(!strcmp(addressBook->contacts[i].phone, phone))
    {
      printf("\033[1;31m");
      printf("Error : Number already exists\n");
      printf("\033[0m");
      return 0;
    }
    
    i++;
  }
  return 1;
}

int validateEmail(AddressBook *addressBook, const char *email)
{
  int i = 0;
  while(i < addressBook->contactCount)
  {
    if(strchr(email,'@')&& strstr(email,".com"))
    {
      if(!strcmp(addressBook->contacts[i].email,email))
      {
        printf("\033[1;31m");
        printf("Error: email already exists\n");
        printf("\033[0m");
        return 0;
      }
    }
    else
    {
      printf("\033[1;31m");
      printf("Error : missing '@' or '.com '\n");
      printf("\033[0m");
      return 0;
    }
    i++;
  }
  return 1;
}


