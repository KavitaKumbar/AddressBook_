#include <stdio.h>
#include<string.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *file = fopen("ContactDirectory.txt","w");
    if(file == NULL)
    {
        printf("File not found: ");
        return ;
    }
    for(int i = 0;i<addressBook ->contactCount;i++)
    {
        fprintf(file,"%s,",addressBook->contacts[i].name);
		fprintf(file,"%s,",addressBook->contacts[i].phone);
		fprintf(file,"%s\n",addressBook->contacts[i].email);
    }
    fclose(file);
  
}

void loadContactsFromFile(AddressBook *addressBook) {
   FILE *file = fopen("ContactDirectory.txt","r");
   if(file == NULL)
   {
    printf("file not found\n");
    return ;
   } 
    addressBook->contactCount = 0;
    char ch;
    while((ch = fgetc(file))!= EOF)
    {
           if(ch == '\n')
           {
            addressBook->contactCount ++;
           }
    }
    rewind(file);
    char tempstr[100];
    int i = 0;
    while(i<addressBook->contactCount)
    {
        fscanf(file,"%[^\n]",tempstr);
        
        char *name =  strtok(tempstr,",");
        char *phone = strtok(NULL,",");
        char *email = strtok(NULL,",");

        strcpy(addressBook ->contacts[i].name,name);
        strcpy(addressBook ->contacts[i].phone,phone);
        strcpy(addressBook ->contacts[i].email,email);

        if(!feof(file))
        fseek(file,+1,SEEK_CUR);

        i++;

     
    }
   fclose(file); 
   
}
